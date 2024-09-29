#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "stdio.h"
#include "beep.h"
int main(void)
{
		//第一步使用RCC开启GPIO时钟
		/*	void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
			void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
			void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
		//第二步使用GPIO_Init函数初始化GPIO
		GPIO_InitTypeDef GPIOB_InitStructure;
		GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_12 ;
		GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOB,&GPIOB_InitStructure);
	
			
	while (1)
    {
	//第三步使用输出或者输入的函数控制GPIO口
    GPIO_SetBits(GPIOB,GPIO_Pin_12);
	play_music();
	
    }

}
