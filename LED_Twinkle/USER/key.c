/*************************************
 * �ļ���  ��key.c
 * ����    ������Ӧ�ú�����        
 * ʵ��ƽ̨��MINI STM32������ ����STM32F103C8T6
 * Ӳ�����ӣ� PA0 - key1          
 * ��汾  ��ST3.0.0 

**********************************************************************************/

#include "key.h" 

 /*����ȷ����ʱ */
 void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

 /*	 ���ð����õ���I/O�� */
void Key_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); //���������˿�PA��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //���������˿�PB��ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //�˿�����Ϊ��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);	//��ʼ���˿�

// 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; 
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //�˿�����Ϊ��������
//	GPIO_Init(GPIOB, &GPIO_InitStructure);	//��ʼ���˿�
}

 /* ����Ƿ��а������� */
u8 Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			
		/*����Ƿ��а������� */
   	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON ) 
	  {	   
	 	 /*��ʱ����*/
	  	Delay(50000);		
	   		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
					{	 
						/*�ȴ������ͷ� */
						while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
			 			return 	KEY_ON;	 
					}
			else
					return KEY_OFF;
		}
	else
		return KEY_OFF;
}