#include <CppUTestExt/MockSupport.h>

extern "C" void led_on (int led)
{
    mock().actualCall("led_on")
        .withParameter("led", led);
}

extern "C" void led_off (int led)
{
    mock().actualCall("led_off")
        .withParameter("led", led);
}
