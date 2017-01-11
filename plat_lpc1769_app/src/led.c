#include <board.h>

void led_on(int led)
{
    Board_LED_Set(led, true);
}

void led_off(int led)
{
    Board_LED_Set(led, false);
}
