#include "ESP8266.h"
#include "HC-05.h"
#include "dma.h"





int ESP_Init(char *ssid, char *password){
	
	short return_flag;
	return_flag = 0;
	
//	Send_HC_05(1,"AT+RST\r\n");
//	delay_ms(500);
//	delay_ms(1000);
//	delay_ms(1000);
	
	return_flag = ESP_send_data_and_check("AT+CWMODE=3\r\n");
	if(return_flag == -1)return -1;
	delay_ms(100);
	return_flag = ESP_Wifi_set(ssid,password);
	if(return_flag == -1)return -2;
	delay_ms(100);
	return_flag = ESP_send_data_and_check("AT+CIPMUX=1\r\n");
	if(return_flag == -1)return -3;
	delay_ms(100);
	return_flag = ESP_send_data_and_check("AT+CIPSERVER=1,5566\r\n");
	if(return_flag == -1)return -4;
	
	
	
	
	return 0;
	
}

int ESP_send_data_and_check(char *p){
	u8 cnt;
	cnt = 0;
	Send_HC_05(1,p);
	
	//Send_HC_05(2,p);  //for test
	Send_HC_05(2,data_ESP);//for test
	
	while((data_ESP[2] != 'K')|(data_ESP[3] != 'O')|(data_ESP[1] != '\r')|(data_ESP[0] != '\n')){ 
		delay_ms(500);
		cnt ++;
		if(cnt == 5) {
			cnt = 0;
			for(cnt=0;cnt<=39;cnt++){
				data_ESP[cnt] = 0;
			}return -1;   //初始化失败
		}
	}
	for(cnt=0;cnt<=39;cnt++){
		data_ESP[cnt] = 0;
	}
//	Send_uart(2,data_ESP); //for test
	
	return 0;
}

int ESP_Wifi_set(char *ssid, char *password){
	u8 cnt;
	cnt = 0;
	
	Send_HC_05(1,"AT+CWJAP=\"");
	Send_HC_05(1,ssid);
	Send_HC_05(1,"\",\"");
	Send_HC_05(1,password);
	Send_HC_05(1,"\"\r\n");
	
//	Send_HC_05(2,"AT+CWJAP=\"");  //for test
//	Send_HC_05(2,ssid);
//	Send_HC_05(2,"\",\"");
//	Send_HC_05(2,password);
//	Send_HC_05(2,"\"\r\n");
	Send_HC_05(2,data_ESP);//for test
	
	
	
	while((data_ESP[2] != 'K')|(data_ESP[3] != 'O')|(data_ESP[1] != '\r')|(data_ESP[0] != '\n')){ 
		delay_ms(500);
		cnt ++;
		if(cnt == 20) {
			cnt=0;
			for(cnt=0;cnt<=39;cnt++){
				data_ESP[cnt] = 0;
			}return -1;   //初始化失败
		}
	}
	for(cnt=0;cnt<=39;cnt++){
		data_ESP[cnt] = 0;
	}
//	Send_uart(2,data_ESP); //for test
	
	
	
	return 0;
	
}

//******************************************************************************//


void ESP_return(int flag){
	switch(flag){
		case(0):{Send_HC_05(1,"AT+CIPSEND=0,6");break;}
		case(1):{Send_HC_05(1,"AT+CIPSEND=0,6");break;}
	}
	
	
}

void Data_ESP_deal(void){
	u8 i;
	i=0;
	for(i=0;i<=40;i++){
		if(data_ESP[i] == ':'){
			break;
		}
		
	}
	for(;i<=40;i++){
		data_ESP[i] = 0;
	}
	
}







