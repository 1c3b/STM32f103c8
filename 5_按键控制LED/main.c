#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "stdio.h"
#include "LED.h"
#include "Key.h"

uint8_t KeyMum;

int main(void)
{
	LED_Init();
    Key_Init();

	while (1)
    {
		KeyMum= Key_GetNum();
		if(KeyMum == 1) {
			LED1_Turn();
		}
		
		if(KeyMum == 2) {
			LED2_Turn();
		}
    }

}
