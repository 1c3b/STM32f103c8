#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encode.h"

int16_t Num;

int main(void)
{
	/*模块初始化*/
	OLED_Init();		//OLED初始化
	Encoder_Init();
	/*OLED显示*/
	OLED_ShowString(1, 3, "Num:");				//1行1列显示字符A

	while (1)
	{
		Num += Encode_Get();
		OLED_ShowSignedNum(1,5,Num,5);
	}
}
