#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "stdio.h"

int main(void)
{
		//第一步使用RCC开启GPIO时钟
		/*	void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
			void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
			void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
		//第二步使用GPIO_Init函数初始化GPIO
		GPIO_InitTypeDef GPIOA_InitStructure;
		GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_All ;
		GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_Init(GPIOA,&GPIOA_InitStructure);
	
			
	while (1)
    {
	//第三步使用输出或者输入的函数控制GPIO口
	uint16_t GPIOB_ODR = 0x0001;
	for(int i = 0;i<8;i++) {
	GPIO_Write(GPIOA,~GPIOB_ODR);//0000 0000 0000 0001
	GPIOB_ODR = GPIOB_ODR<<1;  //最后一位变为0
	Delay_ms(500);	

	}
	
    }

}
