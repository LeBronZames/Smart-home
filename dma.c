#include "dma.h"
#include "usart_2.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK miniSTM32开发板
//DMA 代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/8
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////



#define TEXT_LENTH  sizeof(TEXT_TO_SEND)-1			//TEXT_TO_SEND字符串长度(不包含结束符)













DMA_InitTypeDef DMA_InitStructure;

u16 DMA1_MEM_LEN;//保存DMA每次数据传送的长度 	    
//DMA1的各通道配置
//这里的传输形式是固定的,这点要根据不同的情况来修改
//从存储器->外设模式/8位数据宽度/存储器增量模式
//DMA_CHx:DMA通道CHx
//cpar:外设地址
//cmar:存储器地址
//cndtr:数据传输量 
void MYDMA_Config(DMA_Channel_TypeDef* DMA_CHx,u32 cpar,u32 cmar,u16 cndtr)
{
 	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	//使能DMA传输
	
    DMA_DeInit(DMA_CHx);   //将DMA的通道1寄存器重设为缺省值
	DMA1_MEM_LEN=cndtr;
	DMA_InitStructure.DMA_PeripheralBaseAddr = cpar;  //DMA外设ADC基地址
	DMA_InitStructure.DMA_MemoryBaseAddr = cmar;  //DMA内存基地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;  //数据传输方向，从内存读取发送到外设
	DMA_InitStructure.DMA_BufferSize = cndtr;  //DMA通道的DMA缓存的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;  //外设地址寄存器不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;  //内存地址寄存器递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;  //数据宽度为8位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; //数据宽度为8位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;  //工作在正常缓存模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium; //DMA通道 x拥有中优先级 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  //DMA通道x没有设置为内存到内存传输
	DMA_Init(DMA_CHx, &DMA_InitStructure);  //根据DMA_InitStruct中指定的参数初始化DMA的通道USART1_Tx_DMA_Channel所标识的寄存器
	  	
} 
//开启一次DMA传输
void MYDMA_Enable(DMA_Channel_TypeDef*DMA_CHx)
{ 
	DMA_Cmd(DMA_CHx, DISABLE );  //关闭USART1 TX DMA1 所指示的通道      
 	DMA_SetCurrDataCounter(DMA1_Channel4,DMA1_MEM_LEN);//DMA通道的DMA缓存的大小
 	DMA_Cmd(DMA_CHx, ENABLE);  //使能USART1 TX DMA1 所指示的通道 
}	  

//void DMA_send_data(int a){
//	if(a == 1){
//		USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
//		MYDMA_Enable(DMA1_Channel4);//开始一次DMA传输！	
//		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
//	}
//	else if(a == 2){
//		USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
//		MYDMA_Enable(DMA1_Channel7);//开始一次DMA传输！	
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
//		MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(TEXT_LENTH));//DMA1通道4,外设为串口1,存储器为SendBuff,长(TEXT_LENTH).
//	}
//	else if(a == 2){
//		MYDMA_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)SendBuff,(TEXT_LENTH));//DMA1通道4,外设为串口1,存储器为SendBuff,长(TEXT_LENTH).
//	}
//}
 
void Send_HC_05(int a, char *p){     //最高发送50个字节
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
			for(k = 0;k<=1000;k++){  //加上必要的延时!!!!
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
		MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,(length_buf));//DMA1通道4,外设为串口1,存储器为SendBuff,长(TEXT_LENTH).
	}
	else if(a == 2){
		MYDMA_Config(DMA1_Channel7,(u32)&USART2->DR,(u32)SendBuff,(length_buf));//DMA1通道4,外设为串口1,存储器为SendBuff,长(TEXT_LENTH).
	}
	
	
	
	if(a == 1){
		USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
		MYDMA_Enable(DMA1_Channel4);//开始一次DMA传输！	
		while(DMA_GetCurrDataCounter(DMA1_Channel4)!=0);
		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
	}
	else if(a == 2){
		USART_DMACmd(USART2,USART_DMAReq_Tx,ENABLE); //????1?DMA??        
		MYDMA_Enable(DMA1_Channel7);//开始一次DMA传输！	
		while(DMA_GetCurrDataCounter(DMA1_Channel7)!=0);
		//while(DMA_GetFlagStatus(DMA1_FLAG_TC4)==RESET);
	}
	
}

