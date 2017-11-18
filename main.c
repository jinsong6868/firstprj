#include "stm32f10x.h"
void Delay(u32 count)
{
	u32 i=0;
	for(;i<count;i++);
}
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //ʹ�� PB,PE �˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //LED0-->PB.5 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //IO ���ٶ�Ϊ 50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //��ʼ�� GPIOB.5
	GPIO_SetBits(GPIOA,GPIO_Pin_7);  //PB.5 �����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //LED1-->PE.5 �������
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //��ʼ�� GPIO
	GPIO_SetBits(GPIOA,GPIO_Pin_7); //PE.5 �����
	while(1)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		Delay(3000000);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		Delay(3000000);
	}
}