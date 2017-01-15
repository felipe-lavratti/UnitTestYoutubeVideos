#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*
 * Basic testing guideline:
 * 1) Test all functionalities
 * 2) Test buffer boundaries
 * 3) Test invalid arguments
 */

#include <pthread.h>

extern "C"
{
    #include <my_time.h>
}

/* Ledon and Ledoff mock replacement */
namespace NUT
{
    static void _led_on(int l)
    {
        l = l+1; /* supress warnings */
    }

    static void _led_off(int l)
    {
        l = l+1; /* supress warnings */
    }

    #include "../../app/src/timer.c"
}

using namespace NUT;

TEST_GROUP(TimerHost)
{
    pthread_t th;
    bool keep_running = true;

    void setup ()
    {
    }

    void teardown ()
    {
        keep_running = false;
        pthread_join(th, NULL);
        mock().clear();
    }
};

static void * set_led_loop (void * arg)
{
    bool *keep_running = (bool *)arg;

    while (*keep_running)
    {
        static int i = 0;
        timer_set_led (i%100);
        i += 3;
    }

    return NULL;
}

TEST(TimerHost, SetLedIsr)
{
    pthread_create (&th, NULL, set_led_loop, &keep_running);

    int n = 1000000;
    while (n--)
    {
        timer_process ();
        auto l = cfg_led;

        if (l == 0)
            continue;

        if (l == 1)
            continue;

        FAIL("Not ISR safe!");
    }
}
