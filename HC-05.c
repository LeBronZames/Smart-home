#include "HC-05.h"
#include "dma.h"
#include "LED.h"


//HC-05的功能、以及与其相关的执行函数






void HC_Check(void){
	short i;
	for(i=0;i<=19;i++)
	data_get[i] = 0;
	
	DMA_UART(2,"AT+RESET\r\n");
	delay_ms(500);
	while((data_get[2] != 'K')&&(data_get[3] != '0')&&(data_get[1] != '\r')&&(data_get[0] != '\n')){
		DMA_UART(2,"AT\r\n");
		delay_ms(100);
		LED_flash(6);
	}
	delay_ms(500);
	DMA_UART(2,"AT+ROLE?\r\n");
	delay_ms(500);
	DMA_UART(2,"AT+VERSION?\r\n");
	delay_ms(500);
	DMA_UART(2,"AT+PSWD?\r\n");
	delay_ms(500);
	DMA_UART(2,"AT+UART?\r\n");
	delay_ms(500);
	
}
	

void HC_Order_LED(char *p){
	
	u8 Check_order_buff[20] ;
	u8 length_buf;
	u8 i=0;
	u8 flag;

	flag = 1;
	while(((*p<='~')&&(*p>=' '))|(*p == '\r')|(*p == '\n')){
		Check_order_buff[i] = *p;
		length_buf ++;
		p ++;
		i ++;
	}

//	for(i=0;i<=length_buf-1;i++){
//		USART_SendData(USART1,Check_order_buff[i]);
//		delay_ms(100);
//	}
	

	
	for(i=0;i<=length_buf-1;i++){
			if(data_get[i] != Check_order_buff[length_buf-1-i]){flag = 0;}
		}

	if(flag == 1){
		LED_flash(6);
		for(i=0;i<=length_buf;i++){
			data_get[i] = 0;
		}
		
	}


}

//void HC_Order(void){
//	
//	u8 Check_order_buff[20] ;
//	u8 length_buf;
//	u8 i=0;
//	u8 flag;
//	
//	u8 Order_1[]={"LED"};
//	
//	length_buf = (sizeof Order_1)-1;
//	
//	
//	flag = 1;
//	
//	for(i=0;i<=length_buf-1;i++){
//			Check_order_buff[i] = Order_1[i];
//		}
//	

//	
//	for(i=0;i<=length_buf-1;i++){
//			if(data_get[i] != Check_order_buff[length_buf-1-i]){flag = 0;}
//		}


//	if(flag == 1){
//		LED_flash(6);
//		for(i=0;i<=length_buf;i++){
//			data_get[i] = 0;
//		}
//		
//	}


//}





int HC_Order(void){
	
	u8 Check_order_buff[10][20] ;  //命令缓存级
	u8 length_buf[10]; //固定命令长度
	u8 length_order; //从手机来的命令长度
	u8 i=0,j=0,k=0;
	u8 flag[10];
	int order_bit_diff;  //长度差值，用来分开初级次级命令
	u8 return_flag;
	int flag_all;
	char *Order_1[10]={"LIGHT","CTRL","CCC","DDD","EEE","FFF","GGG","HHH","III","RESET"};
	return_flag = 0;
	order_bit_diff = 0;
	length_order = 0;
	//****************************************赋值检测区*************************//
	
	flag_all = 0;
	
	for(i=0;i<=9;i++){  //0-9的，更改时改i<=9即可
		flag[i] = 1;
		length_buf[i] = 0;
	}i = 0;j=0;
	
	
	for(j=0;j<=9;j++){   //0-9的，更改时改j<=9,以及其中的j
		while(((*Order_1[j]<='~')&&(*Order_1[j]>=' '))|(*Order_1[j] == '\r')|(*Order_1[j] == '\n')){
			Check_order_buff[j][i] = *Order_1[j];
			length_buf[j] ++;
			Order_1[j] ++;
			i ++;
		}
		i = 0;
	}j=0;
	
	//***********************命令检查区**************************//
		k=0;
		while(data_get[k] !=0){    //检测手机来的命令长度
			k++;
			length_order ++;
		}
	
	for(j=0;j<=9;j++){     //0-9的，更改时改j<=9即可

		order_bit_diff = length_order - (length_buf[j]);
		
		for(i=0;i<=length_buf[j]-1;i++){
				if(data_get[i+order_bit_diff] != Check_order_buff[j][length_buf[j]-1-i]){flag[j] = 0;}
			}
		i=0;
	}j = 0;
	
	
	for(i=0;i<=9;i++){    //0-9的，更改时改i<=9即可
		flag_all = flag_all + (int)(flag[i] << i);
		
	}i = 0;
	
	
	

	//*************************命令执行区***************************//

	switch(flag_all){
		case (0x01):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 1;
			break;
		}
		
		case (0x02):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 2;
			break;
		}
		case (0x04):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 3;
			break;
		}
		case (0x08):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 4;
			break;
		}
		case (0x10):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 5;
			break;
		}
		case (0x20):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 6;
			break;
		}
		case (0x40):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 7;
			break;
		}
		case (0x80):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 8;
			break;
		}
		case (0x100):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 9;
			break;
		}
		case (0x200):{
			data_come_flag_next = 1;
//			data_get_clear();
			return_flag = 10;
			break;
		}
		default:{
			return_flag = 0;
			break;
		}
		
	}
	
//	USART_SendData(USART1,return_flag); //for test
	return return_flag;

}


int HC_Order_inner(void){     //次级命令
	
	u8 Check_order_buff[10][20] ;
	u8 length_buf[10];
	u8 i=0,j=0;
	u8 flag[10];
	int return_flag;
	int flag_all;
	char *Order_1[10]={"1","2","3","4","5","6","7","8","9","E"};
	return_flag = 0;
	//****************************************赋值检测区*************************//
	
	flag_all = 0;
	
	for(i=0;i<=9;i++){  //0-9的，更改时改i<=9即可
		flag[i] = 1;
		length_buf[i] = 0;
	}
	i = 0;
	j=0;
	for(j=0;j<=9;j++){   //0-9的，更改时改j<=9,以及其中的j
		while(((*Order_1[j]<='~')&&(*Order_1[j]>=' '))|(*Order_1[j] == '\r')|(*Order_1[j] == '\n')){
			Check_order_buff[j][i] = *Order_1[j];
			length_buf[j] ++;
			Order_1[j] ++;
			i ++;
		}
		i = 0;
	}
	j=0;
	//***********************命令检查区**************************//

	for(j=0;j<=9;j++){     //0-9的，更改时改j<=9即可
		for(i=0;i<=length_buf[j]-1;i++){
				if(data_get[i] != Check_order_buff[j][length_buf[j]-1-i]){flag[j] = 0;}
			}
		i=0;
	}
	j = 0;
	
	for(i=0;i<=9;i++){    //0-9的，更改时改i<=9即可
		flag_all = flag_all + (int)(flag[i] << i);
		
	}
	i = 0;
	
	

	//*************************命令执行区***************************//

	switch(flag_all){
		case (0x01):{
			data_get_clear();
			return_flag = 1;
			break;
		}
		
		case (0x02):{
			data_get_clear();
			return_flag = 2;
			break;
		}
		case (0x04):{
			data_get_clear();
			return_flag = 3;
			break;
		}
		case (0x08):{
			data_get_clear();
			return_flag = 4;
			break;
		}
		case (0x10):{
			data_get_clear();
			return_flag = 5;
			break;
		}
		case (0x20):{
			data_get_clear();
			return_flag = 6;
			break;
		}
		case (0x40):{
			data_get_clear();
			return_flag = 7;
			break;
		}
		case (0x80):{
			data_get_clear();
			return_flag = 8;
			break;
		}
		case (0x100):{
			data_get_clear();
			return_flag = 9;
			break;
		}
		case (0x200):{
			data_get_clear();
			return_flag = 10;
			break;
		}
		default:{
			return_flag = 0;
			break;
		}
		
	}
	return return_flag;
	//data_get_clear(19);

}


//void Execution(int a){
//		u8 TX_ADDRESS_buff_1[TX_ADR_WIDTH]={0x1A,0x3B,0x5C,0x7D,0x9E};
//		u8 RX_ADDRESS_buff_1[TX_ADR_WIDTH]={0x1A,0x3B,0x5C,0x7D,0x9E};
//		int i;
//			switch(a){
//				case(1):{
//					LED_flash(6);
//					
//					break;
//				}
//				case(2):{
//					LED_flash(5);
//					break;
//				}
//				case(3):{
//					break;
//				}
//				case(4):{
//					break;
//				}
//				case(5):{
//					break;
//				}
//				case(6):{
//					break;
//				}
//				case(7):{
//					break;
//				}
//				case(8):{
//					break;
//				}
//				case(9):{
//					wifi_flag = 1;
//					for(i=0;i<=4;i++){
//						TX_ADDRESS[i] = TX_ADDRESS_buff_1[i];
//					}i=0;
//					sent_wifi[0] = 0x55;
//					break;
//				}
//				case(10):{
//					break;
//				}
//				
//				
//			}
//	
//}

void Execution(int a){    //执行函数

		//int i;
			switch(a){
				case(1):{
					//LED_flash(6);
					wifi_flag = 1;
					sent_wifi[0] = 0x01;
					break;
				}
				case(2):{
					//LED_flash(5);
					wifi_flag = 1;
					sent_wifi[0] = 0x02;
					break;
				}
				case(3):{
					wifi_flag = 1;
					sent_wifi[0] = 0x03;
					break;
				}
				case(4):{
					wifi_flag = 1;
					sent_wifi[0] = 0x04;
					break;
				}
				case(5):{
					wifi_flag = 1;
					sent_wifi[0] = 0x05;
					break;
				}
				case(6):{
					wifi_flag = 1;
					sent_wifi[0] = 0x06;
					break;
				}
				case(7):{
					wifi_flag = 1;
					sent_wifi[0] = 0x07;
					break;
				}
				case(8):{
					LED_flash(6);
					wifi_flag = 1;
					sent_wifi[0] = 0x08;
					break;
				}
				case(9):{
					LED_flash(6);
					wifi_flag = 1;
					sent_wifi[0] = 0x09;
					break;
				}
				case(10):{
					break;
				}
				
				
			}
	
}



void data_get_clear(void){      //为简化程序
	int i;
	for(i=0;i<=19;i++){
		data_get[i] = 0;
	}
	for(i=0;i<=39;i++){
		data_ESP[i] = 0;
	}
	i = 0;
}


//	for(i=0;i<=length_buf[0]-1;i++){
//		USART_SendData(USART1,Check_order_buff[i]);
//		delay_ms(100);
//	}


















