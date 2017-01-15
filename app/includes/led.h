#ifndef LED_H
#define LED_H

void _led_on(int);
void _led_off(int);

static inline void led_on (int led)
{
    if (led > 1)
        return;

    if (led < 0)
        return;

    _led_on(led);
}

static inline void led_off (int led)
{
    if (led > 1)
        return;

    if (led < 0)
        return;

    _led_off(led);
}

#endif
