#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

/*
 * Basic testing guideline:
 * 1) Test all functionalities
 * 2) Test buffer boundaries
 * 3) Test invalid arguments
 */

extern "C"
{
    #include <timer.h>
    #include <my_time.h>
}


TEST_GROUP(Timer)
{
    void setup ()
    {
    }

    void teardown ()
    {
        mock().clear();
    }
};

TEST(Timer, Timer)
{
    time_now_cnt = 0;
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("led_on")
        .withIntParameter("led", 0);
    time_now_cnt = 1001;
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("led_off")
        .withIntParameter("led", 0);
    time_now_cnt += 1001;
    timer_process();
    timer_process();

    mock().checkExpectations();
}

TEST(Timer, Elapsed)
{
    CHECK_EQUAL(false, time_elapsed(0, 0xFFFFFFFF, 2));
    CHECK_EQUAL(false, time_elapsed(1, 0xFFFFFFFF, 2));
    CHECK_EQUAL(true, time_elapsed(2, 0xFFFFFFFF, 2));
}
