#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*
 * Basic testing guideline:
 * 1) Test all functionalities
 * 2) Test buffer boundaries
 * 3) Test invalid arguments
 */

#include <pthread.h>
#include <unistd.h>

extern "C"
{
    int am_i_reentrant(int x)
    {
        static int tmp;
        tmp = x;
        return tmp + tmp;
        return x + x;
    }
}

#define ARRAY_SIZE(__arr) (sizeof(__arr)/sizeof(0[__arr]))

struct thread_data
{
    int thread_id;
    int expected;
    bool *keep_running;
};

TEST_GROUP(Reentrant)
{
    pthread_t th[50];
    struct thread_data th_data[ARRAY_SIZE(th)];
    bool keep_running = true;

    void setup ()
    {
    }

    void teardown ()
    {
        keep_running = false;
        for (int i = 0; i < (int)ARRAY_SIZE(th); i++)
            pthread_join(th[i], NULL);
        mock().clear();
    }
};

static void * thread (void * arg)
{
    struct thread_data * data = (struct thread_data *)arg;
    while (*data->keep_running)
    {
        int r = am_i_reentrant(data->thread_id);
        CHECK_EQUAL(data->expected, r);
    }
    return NULL;
}

TEST(Reentrant, reentrant)
{
    for (int i = 0; i < (int)ARRAY_SIZE(th); i++)
    {
        th_data[i].keep_running = &keep_running;
        th_data[i].thread_id = i;
        th_data[i].expected = i + i;
    }

    for (int i = 0; i < (int)ARRAY_SIZE(th); i++)
        pthread_create (&th[i], NULL, thread, &th_data[i]);

    usleep(100000);
}
