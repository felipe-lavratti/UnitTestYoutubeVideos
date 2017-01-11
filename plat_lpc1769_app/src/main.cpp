#include <stdio.h>
#include <chip.h>
#include <board.h>

int main()
{
	printf ("Initializing Board\n");
	Chip_SystemInit();
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock / 1000);

	Board_Init();

    while(1)
    {
    }
}
