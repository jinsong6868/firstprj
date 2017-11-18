#include "stm32f10x.h"
void Delay(u32 count)
{
	u32 i=0;
	for(;i<count;i++);
}
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //使能 PB,PE 端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //LED0-->PB.5 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO 口速度为 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化 GPIOB.5
	GPIO_SetBits(GPIOA,GPIO_Pin_7);  //PB.5 输出高
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //LED1-->PE.5 推挽输出
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化 GPIO
	GPIO_SetBits(GPIOA,GPIO_Pin_7); //PE.5 输出高
	while(1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		Delay(3000000);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		Delay(3000000);
	}
}