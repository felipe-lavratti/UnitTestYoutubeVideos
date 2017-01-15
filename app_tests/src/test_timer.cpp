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
    #include <my_time.h>
    #include <timer.h>
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

TEST(Timer, Process)
{
    time_now_cnt = 0;
    timer_process();
    timer_process();
    mock().checkExpectations();

    time_now_cnt += 500;
    timer_process();
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("_led_on")
        .withIntParameter("led", 0);

    time_now_cnt += 1;
    timer_process();
    mock().checkExpectations();

    time_now_cnt += 500;
    timer_process();
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("_led_off")
        .withIntParameter("led", 0);

    time_now_cnt += 1;
    timer_process();
    mock().checkExpectations();

    time_now_cnt += 500;
    timer_process();
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("_led_on")
        .withIntParameter("led", 0);

    time_now_cnt += 1;
    timer_process();
    mock().checkExpectations();

    time_now_cnt += 500;
    timer_process();
    timer_process();
    timer_process();
    mock().checkExpectations();

    mock().expectOneCall("_led_off")
        .withIntParameter("led", 0);

    time_now_cnt += 1;
    timer_process();
    mock().checkExpectations();
}
