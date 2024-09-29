#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "stdio.h"
#include "LED.h"
#include "Key.h"
#include "LightSensor.h"
#include "Buzzer.h"
uint8_t KeyMum;

int main(void)
{
	LightSensor_Init();
	Buzzer_Init();
	
	while (1)
    {
 	   if(LightSensor_Get() == 1 ) {
			Buzzer_NO();
	   } else {
			Buzzer_Turn();
	   }	
    }

}
