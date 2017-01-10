#include <stdint.h>

volatile uint32_t __time_now = 0;

uint32_t time_now ()
{
	return __time_now;
}

void time_sleep (uint32_t ms)
{
	uint32_t start = __time_now;
    while ((__time_now - start) < ms);
}

__attribute__ ((section(".after_vectors")))
void SysTick_Handler(void)
{
	__time_now++;
}
