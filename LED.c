#include "LED.h"





void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
 GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 输出高

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //LED1-->PE.5 端口配置, 推挽输出
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PE.5 输出高 
}


void LED_flash(short int aaa){  //0是亮
	switch(aaa){
		case 0:{LED0 = 0; LED1 = 0;break;}
		case 1:{LED0 = 1; LED1 = 1;break;}
		case 2:{LED0 = 1; LED1 = 0;break;}
		case 3:{LED0 = 0; LED1 = 1;break;}
		case 4:{LED0 = ~LED0;break;}
		case 5:{LED1 = ~LED1;break;}
		case 6:{LED0 = ~LED0;LED1 = ~LED1;break;}
		default: {LED0 = 0; LED1 = 0;break;}
	}
	
	
	
}





