#include <stdio.h>
#include <chip.h>
#include <board.h>

extern "C"
{
    #include <timer.h>
}

int main()
{
	printf ("Initializing Board\n");
	Chip_SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);

	Board_Init();
	Board_LED_Set(0, true);

    while(1)
    {
        timer_process();
    }
}
