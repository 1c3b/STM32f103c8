#include "beep.h"
#include "stm32f10x.h"                  // Device header

int melody[] = {50, 50, 50, 50, 200, 200, 200, 400, 400, 500, 500, 500};

void BEEP_Init(void)
{   
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能A端口时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
    GPIO_Init(GPIOB, &GPIO_InitStructure);	  //初始化GPIOD3,6
    GPIO_SetBits(GPIOB,GPIO_Pin_12);	
}

void Sound(uint16_t frq)
{
	uint32_t time;
	if(frq != 1000)
	{
		time = 500000/((uint32_t)frq);
		PBeep = 1;
		Delay_us(time);
		PBeep = 0;
		Delay_us(time);
	}else
		delay_us(1000);
}
void Sound2(uint16_t time)
{
    PBeep = 1;
    Delay_us(time);
    PBeep = 0;
    Delay_us(time);
}
void play_successful(void)
{
    int id=0;
    for(id = 0 ;id < 12 ;id++)
    {
        Sound2(melody[id]);
    }
}
void play_failed(void)
{
    int id=0;
    for(id = 11 ;id >=0 ;id--)
    {
        Sound2(melody[id]);
    }
}
void play_music(void)
{
	//              低7  1   2   3   4   5   6   7  高1 高2 高3 高4 高5 不发音
	uint32_t tone[] = {247,262,294,330,349,392,440,294,523,587,659,698,784,1000};//音频数据表
	//红尘情歌
	uint8_t music[]={5,5,6,8,7,6,5,6,13,13,//音调
                5,5,6,8,7,6,5,3,13,13,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,5,13,13,

                5,5,6,8,7,6,5,6,13,13,
                5,5,6,8,7,6,5,3,13,13,
                2,2,3,5,3,5,6,3,2,1,
                6,6,5,6,5,3,6,1,	

                13,8,9,10,10,9,8,10,9,8,6,
                13,6,8,9,9,8,6,9,8,6,5,
                13,2,3,5,5,3,5,5,6,8,7,6,
                6,10,9,9,8,6,5,6,8};	
	uint8_t time[] = {2,4,2,2,2,2,2,8,4, 4, //时间
                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,4 ,4, 

                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,2,2,2,2,8,4, 4, 
                2,4,2,4,2,2,4,2,2,8,
                2,4,2,2,2,2,2,8,

                4, 2,2,2, 4, 2,2,2, 2,2,8,
                4, 2,2,2,4,2,2,2,2,2,8,
                4, 2,2,2,4,2,2,5,2,6,2,4,
                2,2 ,2,4,2,4,2,2,12};	
	uint32_t yanshi;
	uint16_t i,e;
	yanshi = 10;
	for(i=0;i<sizeof(music)/sizeof(music[0]);i++){
		for(e=0;e<((uint16_t)time[i])*tone[music[i]]/yanshi;e++){
			Sound((uint32_t)tone[music[i]]);
		}	
	}
}

