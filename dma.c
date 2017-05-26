#include "dma.h"
#include "usart_2.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK miniSTM32������
//DMA ����	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/8
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////



#define TEXT_LENTH  sizeof(TEXT_TO_SEND)-1			//TEXT_TO_SEND�ַ�������(������������)













DMA_InitTypeDef DMA_InitStructure;

u16 DMA1_MEM_LEN;//����DMAÿ�����ݴ��͵ĳ��� 	    
//DMA1�ĸ�ͨ������
//����Ĵ�����ʽ�ǹ̶���,���Ҫ���ݲ�ͬ��������޸�
//�Ӵ洢��->����ģʽ/8λ���ݿ��/�洢������ģʽ
//DMA_CHx:DMAͨ��CHx
//cpar:�����ַ
//cmar:�洢����ַ
//cndtr:���ݴ����� 
void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx,u32 cpar,u32 cmar,u16 cndtr)
{
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//ʹ��DMA����
	
    DMA_DeInit(DMA_CHx);   //��DMA��ͨ��1�Ĵ�������Ϊȱʡֵ
	DMA1_MEM_LEN=cndtr;
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar;  //DMA����ADC����ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar;  //DMA�ڴ����ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  //���ݴ��䷽�򣬴��ڴ��ȡ���͵�����
	DMA_InitStructure.DMA_BufferSize = cndtr;  //DMAͨ����DMA����Ĵ�С
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //�����ַ�Ĵ�������
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  //�ڴ��ַ�Ĵ�������
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  //���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; //���ݿ��Ϊ8λ
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  //��������������ģʽ
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; //DMAͨ�� xӵ�������ȼ� 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  //DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
	DMA_Init(DMA_CHx, &DMA_InitStructure);  //����DMA_InitStruct��ָ���Ĳ�����ʼ��DMA��ͨ��USART1_Tx_DMA_Channel����ʶ�ļĴ���
	  	
} 
//����һ��DMA����
void MYDMA_Enable(DMA_Channel_TypeDef*DMA_CHx)
{ 
	DMA_Cmd(DMA_CHx, DISABLE );  //�ر�USART1 TX DMA1 ��ָʾ��ͨ��      
 	DMA_SetCurrDataCounter(DMA1_Channel4,DMA1_MEM_LEN);//DMAͨ����DMA����Ĵ�С
 	DMA_Cmd(DMA_CHx, ENABLE);  //ʹ��USART1 TX DMA1 ��ָʾ��ͨ�� 
}	  

//void DMA_send_data(int a){
//	if(a == 1){
//		USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
//		MYDMA_Enable(DMA1_Channel4);//��ʼһ��DMA���䣡	
//		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
//	}
//	else if(a == 2){
//		USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
//		MYDMA_Enable(DMA1_Channel7);//��ʼһ��DMA���䣡	
//		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
//	}
//	
//}
//void DMA_uart_init(int a, u8 *p){
//	int i;
//	u8 TEXT_TO_SEND[]={"ALIENTEK Mini STM32 DMA\r\n"};
//	u8 SendBuff[(TEXT_LENTH)];
//	
//	
//	for(i=0;i<=(TEXT_LENTH);i++){
//		SendBuff[i] = TEXT_TO_SEND[i];
//	}
//	
//	
//	if(a == 1){
//		MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(TEXT_LENTH));//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,��(TEXT_LENTH).
//	}
//	else if(a == 2){
//		MYDMA_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)SendBuff,(TEXT_LENTH));//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,��(TEXT_LENTH).
//	}
//}
 
void Send_HC_05(int a, char *p){     //��߷���50���ֽ�
	int i,j,k;
	int length_buf;
	//u8 TEXT_TO_SEND[]={"ALIENTEK Mini STM32 DMA\r\n"};
	u8 SendBuff[50];
	length_buf = 0;
	i = 0;j = 0;k = 0;
	
	for(i=0;i<=49;i++){
		SendBuff[i] = 0;
	}i=0;
	
	while(((*p<='~')&&(*p>=' '))|(*p == '\r')|(*p == '\n')){
		SendBuff[i] = *p;
		length_buf ++;
		p ++;
		i ++;
	} i = 0;
	
	if(a == 1){
		for(i=0;i<=(length_buf-1);i++){
			USART_SendData(USART1,SendBuff[i]);
			for(k = 0;k<=1000;k++){  //���ϱ�Ҫ����ʱ!!!!
				for(j=0;j<=50;j++);
			}j = 0;k = 0;
		}i=0;
	}
	else if(a == 2){
		for(i=0;i<=(length_buf-1);i++){
			USART_SendData(USART2,SendBuff[i]);
			for(k = 0;k<=1000;k++){
				for(j=0;j<=50;j++);
			}j = 0;k = 0;
			
		}i=0;
	}
	
}
 

void DMA_UART(int a, char *p){
	
	int i;
	int length_buf;
	//u8 TEXT_TO_SEND[]={"ALIENTEK Mini STM32 DMA\r\n"};
	u8 SendBuff[(200)];
	length_buf = 0;
	i = 0;
	
	while(((*p<='~')&&(*p>=' '))|(*p == '\r')|(*p == '\n')){
		SendBuff[i] = *p;
		length_buf ++;
		p ++;
		i ++;
	}
	
	
//	for(i=0;i<=(length_buf);i++){
//		SendBuff[i] = *p;
//	}
	
	
	if(a == 1){
		MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(length_buf));//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,��(TEXT_LENTH).
	}
	else if(a == 2){
		MYDMA_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)SendBuff,(length_buf));//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,��(TEXT_LENTH).
	}
	
	
	
	if(a == 1){
		USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
		MYDMA_Enable(DMA1_Channel4);//��ʼһ��DMA���䣡	
		while(DMA_GetCurrDataCounter(DMA1_Channel4)!=0);
		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
	}
	else if(a == 2){
		USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
		MYDMA_Enable(DMA1_Channel7);//��ʼһ��DMA���䣡	
		while(DMA_GetCurrDataCounter(DMA1_Channel7)!=0);
		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
	}
	
}

