#include <stdint.h>
#include <stdbool.h>

#include "my_time.h"
#include "led.h"

static uint32_t last = 0;
static bool state = false;
static int cfg_led = 0;

// ISR Safe
void timer_set_led (int led)
{
    cfg_led = led % 2;
}

void timer_process ()
{
    uint32_t now = time_now();

    if (!time_elapsed(now, last, 500))
        return;

    if (state)
        led_off(cfg_led);
    else
        led_on(cfg_led);

    state = !state;
    last = now;
}
