#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "stdio.h"
#include "LED.h"
#include "Key.h"
#include "OLED.h"
#include "COUNTSENSOR.H"

uint8_t KeyMum;

int main(void)
{
	OLED_Init();
	CountSensor_Init();

	OLED_ShowString(1,1,"count: ");

	while (1)
    {
		OLED_ShowNum(1,7,CountSensor_Get(),5);
    }

}
