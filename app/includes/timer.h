#ifndef TIMER_H
#define TIMER_H

#ifdef __cplusplus
extern "C"  {
#endif

void timer_process ();

// ISR Safe
void timer_set_led (int);

#ifdef __cplusplus
}
#endif

#endif
