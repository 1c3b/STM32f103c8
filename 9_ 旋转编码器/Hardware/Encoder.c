#include "stm32f10x.h"                  // Device header

int16_t EncodeCount;
void Encoder_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//EXIT不需要开启外设
	GPIO_InitTypeDef GPIOB_InitStruct;
	GPIOB_InitStruct.GPIO_Mode = GPIO_Mode_IPU ;
	GPIOB_InitStruct.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;
	GPIOB_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIOB_InitStruct);
    
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	
	EXTI_InitTypeDef EXTI_InitSture;
	EXTI_InitSture.EXTI_Line = EXTI_Line0|EXTI_Line1;
	EXTI_InitSture.EXTI_LineCmd = ENABLE;
	EXTI_InitSture.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitSture.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitSture);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组只能进行一次
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);

}

int16_t Encode_Get(void)
{
	int16_t Temp;
	Temp = EncodeCount;
	EncodeCount = 0;
	return Temp;
}
void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line0)== SET) {
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)
		{
			EncodeCount--;
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void EXTI1_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line1)== SET) {
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0)
		{
			EncodeCount++;
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
