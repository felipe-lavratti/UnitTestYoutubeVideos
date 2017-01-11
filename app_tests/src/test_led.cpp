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
     #include <led.h>
}

TEST_GROUP(Led)
{
    void setup ()
    {
    }

    void teardown ()
    {
        mock().clear();
    }
};

TEST(Led, LedOn)
{
    mock().expectOneCall("led_on")
        .withIntParameter("led", 0);
    mock().expectOneCall("led_on")
        .withIntParameter("led", 1);

    led_on(0);
    led_on(1);
}


TEST(Led, LedOff)
{
    mock().expectOneCall("led_off")
        .withIntParameter("led", 0);
    mock().expectOneCall("led_off")
        .withIntParameter("led", 1);

    led_off(0);
    led_off(1);
}
