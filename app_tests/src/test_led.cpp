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

TEST(Led, Ledon)
{
    mock().expectOneCall("_led_on")
        .withIntParameter("led", 0);
    mock().expectOneCall("_led_on")
        .withIntParameter("led", 1);

    led_on (-1);
    led_on (0);
    led_on (1);
    led_on (2);
    led_on (7387289);
    led_on (-7387289);
}

TEST(Led, Ledoff)
{
    mock().expectOneCall("_led_off")
        .withIntParameter("led", 0);
    mock().expectOneCall("_led_off")
        .withIntParameter("led", 1);

    led_off (-1);
    led_off (0);
    led_off (1);
    led_off (2);
    led_off (1675156);
    led_off (-163816);
}
