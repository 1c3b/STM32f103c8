#include "stm32f10x.h"                  // Device header

uint16_t CountSensorcount;
void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//EXIT不需要开启外设
	GPIO_InitTypeDef GPIOB_InitStruct;
	GPIOB_InitStruct.GPIO_Mode = GPIO_Mode_IPU ;
	GPIOB_InitStruct.GPIO_Pin = GPIO_Pin_14;
	GPIOB_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitStruct);
    
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	
	EXTI_InitTypeDef EXTI_InitSture;
	EXTI_InitSture.EXTI_Line = EXTI_Line14;
	EXTI_InitSture.EXTI_LineCmd = ENABLE;
	EXTI_InitSture.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitSture.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitSture);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组只能进行一次
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Get(void)
{
	return CountSensorcount;
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line14) == SET)
	{
		CountSensorcount++;
	    EXTI_ClearITPendingBit(EXTI_Line14);
	}
}
