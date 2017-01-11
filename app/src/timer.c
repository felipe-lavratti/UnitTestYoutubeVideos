#include <stdbool.h>
#include <stdint.h>

#include "led.h"
#include "timer.h"
#include "my_time.h"

static uint32_t last_time = 0;
static bool led_state = false;

void timer_process ()
{
    uint32_t now = time_now();

    if (!time_elapsed(now, last_time, 1000))
        return;

    last_time = now;

    if (!led_state)
        led_on(0);
    else
        led_off(0);

    led_state = !led_state;
}
