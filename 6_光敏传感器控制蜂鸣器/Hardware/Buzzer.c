#include "stm32f10x.h"                  // Device header


void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIOB_InitStruct;
	GPIOB_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIOB_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIOB_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitStruct);
}

void Buzzer_NO(void)
{
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}	

void Buzzer_OFF(void)
{
    GPIO_SetBits(GPIOB,GPIO_Pin_12);
}	

void Buzzer_Turn(void)
{
    if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1) == 0) {
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
	}else {
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	}
}
