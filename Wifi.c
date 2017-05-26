#include "Wifi.h"
#include "HC-05.h"
#include "dma.h"
#include "LED.h"
#include "LDC.h"
#include "ESP8266.h"

void WiFi_Operate(void){    //第一步判断命令子系统标号，并进入目标操作函数
	
	switch(get_wifi[0]){

		case(1):{
			Operate_01();
			break;
		}
		case(2):{
			Operate_02();
			break;
		}
		case(3):{
			
			break;
		}
		case(4):{
			
			break;
		}
		case(5):{
			
			break;
		}
		case(6):{
			
			break;
		}
		case(7):{
			
			break;
		}
		case(8):{
			
			break;
		}
		case(9):{
			
			break;
		}
		case(10):{
			
			break;
		}
		case(11):{
			
			break;
		}
		case(12):{
			
			break;
		}
		case(13):{
			
			break;
		}
		case(14):{
			
			break;
		}
		case(15):{
			
			break;
		}
		case(16):{
			
			break;
		}
		case(17):{
			
			break;
		}
		case(18):{
			LED_flash(6);
			Operate_18();
			break;
		}		
		
	}
	
}


//*****************************子系统命令识别执行函数****************//

u8 rain_flag;

void Operate_18(void){         //下雨传感器
	if(get_wifi[1] == 1){
		Send_HC_05(2,"Warning!!!! Raining now!!\r\n");
		Send_HC_05(1,"AT+CIPSEND=0,8\r\n");
		Send_HC_05(1,"Raining!");
		rain_flag = 1; 
	}
	else if(get_wifi[1] == 2){
		Send_HC_05(2,"OK, The weather is fine now~~\r\n");
		Send_HC_05(1,"AT+CIPSEND=0,8\r\n");
		Send_HC_05(1,"Nice Day");
		rain_flag = 0;
	}
	
	
}


u16 light_lex;

void Operate_01(void){  //灯模块之光强度传递
	static u8 send_flag_01_1 = 0;
	static u8 send_flag_01_2 = 0;
	
	light_lex = (get_wifi[1]<<8) + get_wifi[2];

	if(page_flag == 11){
		LCD_ShowNum(80,295,light_lex,5,16);
		if(get_wifi[3] == 1){
			LCD_ShowString(140,285,200,1,16,"A");
			if(send_flag_01_1 == 0){
				Send_HC_05(2,"A");
				
				Send_HC_05(1,"AT+CIPSEND=0,6\r\n");
				Send_HC_05(1,"AUTO  ");

				send_flag_01_1 = 1; //发送过了
				send_flag_01_2 = 0;
			}
			
		}
		else if(get_wifi[3] == 0){
			LCD_ShowString(140,285,200,1,16,"M");
			if(send_flag_01_2 == 0){
				Send_HC_05(2,"M");
				
				Send_HC_05(1,"AT+CIPSEND=0,6\r\n");
				Send_HC_05(1,"MANUAL");
				
				send_flag_01_2 = 1; //发送过了
				send_flag_01_1 = 0;
			}
		}
	}
	
}



void Operate_02(void){  //万能遥控器模块
	static u8 send_flag_02_1 = 0;
	static u8 send_flag_02_2 = 0;
	if(page_flag == 12){
		if(get_wifi[1] == 0){  //正常模式
			LCD_ShowString(100,285,200,6,16,"Normal");
			if(send_flag_02_1 == 0){
				Send_HC_05(2,"Normal");
				
				Send_HC_05(1,"AT+CIPSEND=0,6\r\n");
				Send_HC_05(1,"Normal");
				
				send_flag_02_1 = 1; //发送过了
				send_flag_02_2 = 0;
			}
		}
		else if(get_wifi[1] == 1){  //学习模式
			LCD_ShowString(100,285,200,6,16,"LEARN ");
			if(send_flag_02_2 == 0){
				Send_HC_05(2,"LEARN ");
				
				Send_HC_05(1,"AT+CIPSEND=0,6\r\n");
				Send_HC_05(1,"LEARN ");
				
				send_flag_02_2 = 1; //发送过了
				send_flag_02_1 = 0;
			}
		}
	}
}




