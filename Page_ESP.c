













#include "ESP8266.h"
#include "Page_ESP.h"
#include "LDC.h"
#include "stdlib.h"
#include "usart.h"
#include "delay.h"	 
#include "rtc.h"
#include "Page.h"
#include "Touch.h"
#include "HC-05.h"
#include "Page_expand.h"
#include "LED.h"


u8 data_input_ESP_abc[10]; //���ڴ洢wifi��Ϣ

u8 SSID_PASSWORD_flag; //==0 SSID

void page_operation_ESP_set(int flag){
	int k;
	k=0;
	if(flag == 10){  //���ز˵���
		
		
		
		while(ESP_Init(ssid_esp, password_esp) != 0){ //check ESP8266//test pass!!!
			delay_ms(100);
			LED_flash(6);
			k++;
			if(k == 5){//ESPû����Ӧ
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				LCD_Fill(0,50,300,250,0x5656);
				LCD_ShowString(25,100,130,30,16,"ERROR!!Data hasn't changed");
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;
				delay_ms(500);delay_ms(500);
				delay_ms(500);delay_ms(500);
				break;
			}
		}
		
		
		
		
		page_flag = 0;
		data_ESP_flag = 0; 
		page_init();
			
	}
		
	else if(flag == 11){  //�˺�
			page_flag_buf = page_flag;
			page_flag = 102; //
		
			page_input_2();
			POINT_COLOR = 0x0000;
			BACK_COLOR = 0x5656;
			
			LCD_ShowString(10,50,200,1,16," /0");
			LCD_ShowString(10+85,50,200,1,16,"abc/1");
			LCD_ShowString(10+85+85,50,200,1,16,"def/2");
			LCD_ShowString(10,50+85,200,1,16,"ghi/3");
			LCD_ShowString(10+85,50+85,200,1,16,"jkl/4");
			LCD_ShowString(10+85+85,50+85,200,1,16,"mno/5");
			LCD_ShowString(10,50+85+85,200,1,16,"pqrs/6");
			LCD_ShowString(10+85,50+85+85,200,1,16,"tuv/7");
			LCD_ShowString(10+85+85,50+85+85,200,1,16,"wxyz/89");
			
			POINT_COLOR = 0x0000;
			BACK_COLOR = 0xffff;
			SSID_PASSWORD_flag = 0;
	}
	else if(flag == 12){//����
			page_flag_buf = page_flag;
			page_flag = 102; 
			page_input_2();
			POINT_COLOR = 0x0000;
			BACK_COLOR = 0x5656;
			
			LCD_ShowString(10,50,200,1,16," /0");
			LCD_ShowString(10+85,50,200,1,16,"abc/1");
			LCD_ShowString(10+85+85,50,200,1,16,"def/2");
			LCD_ShowString(10,50+85,200,1,16,"ghi/3");
			LCD_ShowString(10+85,50+85,200,1,16,"jkl/4");
			LCD_ShowString(10+85+85,50+85,200,1,16,"mno/5");
			LCD_ShowString(10,50+85+85,200,1,16,"pqrs/6");
			LCD_ShowString(10+85,50+85+85,200,1,16,"tuv/7");
			LCD_ShowString(10+85+85,50+85+85,200,1,16,"wxyz/89");
			
			POINT_COLOR = 0x0000;
			BACK_COLOR = 0xffff;
			SSID_PASSWORD_flag = 1;
	}
	
	else {     //�ı�ssid��password
		
	}
}


void page_input_ESP(void){      //�˺�������ʾ����
  int i;
	i = page_flag -10 - 1;
	SSID_PASSWORD_flag = 0;
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_Fill(15,50+75,250,161,0x5656);
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	LCD_ShowString(25,100,130,1,16,"SSID:");
	LCD_ShowString(150,100,200,1,16,ssid_esp);
	LCD_ShowString(25,140,150,1,16,"PASSWORD:");		
	LCD_ShowString(150,140,200,1,16,password_esp);	
	
	
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	LCD_ShowString(90,285,200,4,16,"SSID");
	

	draw_line(265);
	LCD_ShowString(20,285,200,6,16,"<<BACK");
	
	LCD_ShowString(150,285,200,8,16,"PASSWORD");    //��ʾ���Ƶ�ǰ��ģ��
	for(i=0;i<=9;i++){
		data_input_ESP_abc[i] = 0;
	}
	
}



u8 OK_in_2_flag_ESP = 0;  //��������ȷ��, ==0��ʾ����ok��������ȷ���ַ� �� ==1��ʾ����ȷ����������


void page_operation_s_input_ESP(int flag){   //time set
	int k;
	int aaa;
	static u8 data_one_ESP;
	static u8 Cap_flag = 0;
	static u8 abc_flag_ESP[10]={0,0,0,0,0,0,0,0,0,0};
	
	
	
	k = 0; aaa = 1;
	
		switch(flag){
		case(1):{
			switch(abc_flag_ESP[1]){
				case(0):{abc_flag_ESP[1] = 1;data_one_ESP = ' ';OK_in_2_flag_ESP = 0;break;}
				case(1):{abc_flag_ESP[1] = 0;data_one_ESP = '0';OK_in_2_flag_ESP = 0;break;}
				break;
			}
		}
		case(2):{
			switch(abc_flag_ESP[2]){
				case(0):{ abc_flag_ESP[2] = 1; if(Cap_flag == 0)data_one_ESP = 'a';else if(Cap_flag == 1)data_one_ESP = 'A'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;} //������ʾ������ʲô
				case(1):{ abc_flag_ESP[2] = 2; if(Cap_flag == 0)data_one_ESP = 'b';else if(Cap_flag == 1)data_one_ESP = 'B'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[2] = 3; if(Cap_flag == 0)data_one_ESP = 'c';else if(Cap_flag == 1)data_one_ESP = 'C'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[2] = 0; if(Cap_flag == 0)data_one_ESP = '1';else if(Cap_flag == 1)data_one_ESP = '1'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(3):{
			switch(abc_flag_ESP[3]){
				case(0):{ abc_flag_ESP[3] = 1; if(Cap_flag == 0)data_one_ESP = 'd';else if(Cap_flag == 1)data_one_ESP = 'D'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[3] = 2; if(Cap_flag == 0)data_one_ESP = 'e';else if(Cap_flag == 1)data_one_ESP = 'E'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[3] = 3; if(Cap_flag == 0)data_one_ESP = 'f';else if(Cap_flag == 1)data_one_ESP = 'F'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[3] = 0; if(Cap_flag == 0)data_one_ESP = '2';else if(Cap_flag == 1)data_one_ESP = '2'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(4):{
			switch(abc_flag_ESP[4]){
				case(0):{ abc_flag_ESP[4] = 1; if(Cap_flag == 0)data_one_ESP = 'g';else if(Cap_flag == 1)data_one_ESP = 'G'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[4] = 2; if(Cap_flag == 0)data_one_ESP = 'h';else if(Cap_flag == 1)data_one_ESP = 'H'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[4] = 3; if(Cap_flag == 0)data_one_ESP = 'i';else if(Cap_flag == 1)data_one_ESP = 'I'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[4] = 0; if(Cap_flag == 0)data_one_ESP = '3';else if(Cap_flag == 1)data_one_ESP = '3'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(5):{
			switch(abc_flag_ESP[5]){
				case(0):{ abc_flag_ESP[5] = 1; if(Cap_flag == 0)data_one_ESP = 'j';else if(Cap_flag == 1)data_one_ESP = 'J'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[5] = 2; if(Cap_flag == 0)data_one_ESP = 'k';else if(Cap_flag == 1)data_one_ESP = 'K'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[5] = 3; if(Cap_flag == 0)data_one_ESP = 'l';else if(Cap_flag == 1)data_one_ESP = 'L'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[5] = 0; if(Cap_flag == 0)data_one_ESP = '4';else if(Cap_flag == 1)data_one_ESP = '4'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(6):{
			switch(abc_flag_ESP[6]){
				case(0):{ abc_flag_ESP[6] = 1; if(Cap_flag == 0)data_one_ESP = 'm';else if(Cap_flag == 1)data_one_ESP = 'M'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[6] = 2; if(Cap_flag == 0)data_one_ESP = 'n';else if(Cap_flag == 1)data_one_ESP = 'N'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[6] = 3; if(Cap_flag == 0)data_one_ESP = 'o';else if(Cap_flag == 1)data_one_ESP = 'O'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[6] = 0; if(Cap_flag == 0)data_one_ESP = '5';else if(Cap_flag == 1)data_one_ESP = '5'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(7):{
			switch(abc_flag_ESP[7]){
				case(0):{ abc_flag_ESP[7] = 1; if(Cap_flag == 0)data_one_ESP = 'p';else if(Cap_flag == 1)data_one_ESP = 'P'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[7] = 2; if(Cap_flag == 0)data_one_ESP = 'q';else if(Cap_flag == 1)data_one_ESP = 'Q'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[7] = 3; if(Cap_flag == 0)data_one_ESP = 'r';else if(Cap_flag == 1)data_one_ESP = 'R'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[7] = 4; if(Cap_flag == 0)data_one_ESP = 's';else if(Cap_flag == 1)data_one_ESP = 'S'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(4):{ abc_flag_ESP[7] = 0; if(Cap_flag == 0)data_one_ESP = '6';else if(Cap_flag == 1)data_one_ESP = '6'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(8):{
			switch(abc_flag_ESP[8]){
				case(0):{ abc_flag_ESP[8] = 1; if(Cap_flag == 0)data_one_ESP = 't';else if(Cap_flag == 1)data_one_ESP = 'T'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[8] = 2; if(Cap_flag == 0)data_one_ESP = 'u';else if(Cap_flag == 1)data_one_ESP = 'U'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[8] = 3; if(Cap_flag == 0)data_one_ESP = 'v';else if(Cap_flag == 1)data_one_ESP = 'V'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[8] = 0; if(Cap_flag == 0)data_one_ESP = '7';else if(Cap_flag == 1)data_one_ESP = '7'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		case(9):{
			switch(abc_flag_ESP[9]){
				case(0):{ abc_flag_ESP[9] = 1; if(Cap_flag == 0)data_one_ESP = 'w';else if(Cap_flag == 1)data_one_ESP = 'W'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(1):{ abc_flag_ESP[9] = 2; if(Cap_flag == 0)data_one_ESP = 'x';else if(Cap_flag == 1)data_one_ESP = 'X'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(2):{ abc_flag_ESP[9] = 3; if(Cap_flag == 0)data_one_ESP = 'y';else if(Cap_flag == 1)data_one_ESP = 'Y'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(3):{ abc_flag_ESP[9] = 4; if(Cap_flag == 0)data_one_ESP = 'z';else if(Cap_flag == 1)data_one_ESP = 'Z'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(4):{ abc_flag_ESP[9] = 5; if(Cap_flag == 0)data_one_ESP = '8';else if(Cap_flag == 1)data_one_ESP = '8'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
				case(5):{ abc_flag_ESP[9] = 0; if(Cap_flag == 0)data_one_ESP = '9';else if(Cap_flag == 1)data_one_ESP = '9'; LCD_ShowString(80,275,200,1,16,&data_one_ESP);OK_in_2_flag_ESP = 0; break;}
			}
			break;
		}
		
		
		
		case(11):{
			if(Cap_flag == 0) {  //��Сд�л�
				Cap_flag = 1;
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				
				LCD_ShowString(10,50,200,1,16," /0");
				LCD_ShowString(10+85,50,200,1,16,"ABC/1");
				LCD_ShowString(10+85+85,50,200,1,16,"DEF/2");
				LCD_ShowString(10,50+85,200,1,16,"GHI/3");
				LCD_ShowString(10+85,50+85,200,1,16,"JKL/4");
				LCD_ShowString(10+85+85,50+85,200,1,16,"MNO/5");
				LCD_ShowString(10,50+85+85,200,1,16,"PQRS/6");
				LCD_ShowString(10+85,50+85+85,200,1,16,"TUV/7");
				LCD_ShowString(10+85+85,50+85+85,200,1,16,"WXYZ/89");
				
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;
			}
			else if(Cap_flag == 1) {
				Cap_flag = 0;
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				
				LCD_ShowString(10,50,200,1,16," /0");
				LCD_ShowString(10+85,50,200,1,16,"abc/1");
				LCD_ShowString(10+85+85,50,200,1,16,"def/2");
				LCD_ShowString(10,50+85,200,1,16,"ghi/3");
				LCD_ShowString(10+85,50+85,200,1,16,"jkl/4");
				LCD_ShowString(10+85+85,50+85,200,1,16,"mno/5");
				LCD_ShowString(10,50+85+85,200,1,16,"pqrs/6");
				LCD_ShowString(10+85,50+85+85,200,1,16,"tuv/7");
				LCD_ShowString(10+85+85,50+85+85,200,1,16,"wxyz/89");
				
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;

			}
			
			
			
			break;
		}
		
		
		case(10):{    //BACK/DEL
			LCD_ShowString(80,275,200,1,16," ");//���������һ�ε����֣�Ϊ��һ����׼��
			LCD_ShowString(80,295,200,10,16,"          "); //���������һ�ε����֣�Ϊ��һ����׼��
			LCD_ShowString(80,295,200,10,16,data_input_ESP_abc);
			aaa = 1;
			for(k=0;k<=9;k++){    //<<DEL and <<BACK
			if(data_input_ESP_abc[k] != 0)
				aaa = 0;
			}k=0;
			
			if(aaa == 1){  //��ssid��ʾ����
				page_input_ESP();
				page_flag = 19;
			}
		
			else{
//				for(k=0;k<=9;k++){
//					data_input_ESP_abc[k] = data_input_ESP_abc[k+1];
//				}data_input_ESP_abc[9] = 0; k = 0;
				for(k=0;k<=9;k++){              //�ж����һλ���ģ�Ȼ��ɾ��
					if(data_input_ESP_abc[k] == 0){
						data_input_ESP_abc[k - 1] = 0;
						break;
					}
					if(k == 9){         //���һλɾ��
						data_input_ESP_abc[9] = 0;
					}
				}
				
				
				LCD_ShowString(80,275,200,1,16," ");//���������һ�ε����֣�Ϊ��һ����׼��
				LCD_ShowString(80,295,200,10,16,"          "); //���������һ�ε����֣�Ϊ��һ����׼��
				LCD_ShowString(80,295,200,10,16,data_input_ESP_abc);
					
				for(k=0;k<=9;k++){
					if(data_input_ESP_abc[k] != 0){  //�ж���һ����ʾdel����back
						LCD_ShowString(20,285,200,6,16,"<<DEL ");
						break;
					}
					else LCD_ShowString(20,285,200,6,16,"<<BACK");
				}
				
				
				
				
			}
			
			break;
		}
		
		
		case(12):{      //OK
			
			
			if(OK_in_2_flag_ESP == 1){      //������ȷ�����Ըı�����
				
				//***********************************************************//
				
				//Send_HC_05(2,data_input_ESP_abc);  //for test //��ĸ���ڣ�����
				if(SSID_PASSWORD_flag == 0){
					for(k=0;k<=9;k++){
						ssid_esp[k] = data_input_ESP_abc[k];
					}
				}
				else if(SSID_PASSWORD_flag == 1){
					for(k=0;k<=9;k++){
						password_esp[k] = data_input_ESP_abc[k];
					}
				}
				
				
				page_input_ESP();
				page_flag = 19;
				
				
				
				
				
				
				//******************************************************//
				
				
//				for(k=0;k<=13;k++){    //ͬʱ����
//					data_input_ESP_abc[k] = 0;
//				}
				
				OK_in_2_flag_ESP = 0;
				
				
				
			}
			
			else if(OK_in_2_flag_ESP == 0){  //ȷ����ĸ
//				for(k=1;k<=9;k++){
//						data_input_ESP_abc[k-1] = data_input_ESP_abc[k];
//					}
//				data_input_ESP_abc[9] = data_one_ESP; k = 0;
				for(k=0;k<=9;k++){
					if(data_input_ESP_abc[k] == 0){
						data_input_ESP_abc[k] = data_one_ESP;
						break;
					}
				}
				
				for(k=0;k<=9;k++){
					abc_flag_ESP[k] = 0;
				}
					
				OK_in_2_flag_ESP = 1;
				
				LCD_ShowString(80,275,200,1,16," ");//���������һ�ε����֣�Ϊ��һ����׼��
				LCD_ShowString(80,295,200,10,16,"          "); //���������һ�ε����֣�Ϊ��һ����׼��
				LCD_ShowString(80,295,200,10,16,data_input_ESP_abc); //���������
				LCD_ShowString(20,285,200,6,16,"<<DEL "); //����һ��ok����һ��һ����del
			}
				
		}
			
			
			
			
			
			break;
	}
	
	
}


