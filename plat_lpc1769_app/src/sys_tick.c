#include <stdint.h>

// volatile uint32_t time_now_cnt = 0;

__attribute__ ((section(".after_vectors")))
void SysTick_Handler(void)
{
}
