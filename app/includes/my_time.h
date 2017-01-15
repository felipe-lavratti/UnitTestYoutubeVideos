#ifndef MY_TIME_H
#define MY_TIME_H

#include <stdint.h>

extern volatile uint32_t time_now_cnt;

static inline uint32_t time_now()
{
    return time_now_cnt;
}

// Later has to be past related to now.
static inline bool time_elapsed(uint32_t now, uint32_t later, uint32_t elapsed)
{
    return (now - later) > elapsed;
}

#endif
