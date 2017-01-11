#ifndef MY_TIME_H
#define MY_TIME_H

#include <stdint.h>
#include <stdbool.h>

extern uint32_t time_now_cnt;

static inline uint32_t time_now() {
    return time_now_cnt;
}

static inline bool time_elapsed(uint32_t now,
                                uint32_t past,
                                uint32_t elapsed)
{
    return (now - past) > elapsed;
}

#endif
