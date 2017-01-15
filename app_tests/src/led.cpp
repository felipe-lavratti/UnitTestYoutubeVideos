#include <CppUTestExt/MockSupport.h>


extern "C" void _led_on (int led)
{
    mock().actualCall("_led_on")
        .withParameter("led", led);
}

extern "C" void _led_off (int led)
{
    mock().actualCall("_led_off")
        .withParameter("led", led);
}
