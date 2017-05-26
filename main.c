#include "HC-05.h"
#include "LDC.h"
#include "LED.h"
#include "usart_2.h"	
#include "dma.h"
#include "nrf24l01.h"
#include "Touch.h"
#include "DHT22.h"
#include "Wifi.h"
#include "rtc.h"
#include "Page.h"
#include "ESP8266.h"
#include "Page_ESP.h"
#include "includes.h"




void Init_all(void);
void Wifi_send(void);



u8 data_ESP[40]; //ESP8266��������
u8 data_ESP_flag;

u8 data_get[20];  //���20�ַ��Ľ������������ݻ���
u8 data_come_flag; //UART2���յ��������ݵ�Flag
u8 data_come_flag_next;  //�μ�����flag
int i;
u8 get_wifi[32];  //�ڱ�����У�NRF���WiFi
u8 sent_wifi[32];
u8 wifi_flag;
int page_flag = 0;  //�ж�ҳ������	
int page_flag_buf = 0;//���ڷ��ز˵�
u8 data_input_set[14];  //���ڴ洢����ʱ����Ϣ
u8 data_input_abc[20][10]; //���ڴ洢������Ϣ����ĸ��

char ssid_esp[10] = {"lv"};
char password_esp[10] = {"12121212"};


char *a[9] = {"Light","CTRL","CCC","DDD","EEE","FFF","GGG","HHH","ESP8266"};
char *b[9] = {"JJJ","KKK","LLL","MMM","NNN","OOO","PPP","Temp-Humi","Weather"};
u8 aa[9][10];
u8 bb[9][10];

extern const u8 mobilephone_bmp[];

extern u8 rain_flag;  //1 is raining
	
	

u8 TX_ADDRESS_ok[5]={0x1A,0x3B,0x5C,0x7D,0x9E};//����ַ
u8 RX_ADDRESS_ok[5]={0x1A,0x3B,0x5C,0x7D,0x9E};

u8 TX_ADDRESS[5]={0x1A,0x3B,0x5C,0x7D,0x9E}; //�ɱ仯���͵�ַ
u8 RX_ADDRESS[5]={0x1A,0x3B,0x5C,0x7D,0x9E}; //


#define P_Level_Start 10
#define P_Level_Bluetooth 9
#define P_Level_Wifi 8
#define P_Level_Time 7
#define P_Level_Touch 6
#define P_Level_T_and_H 5

#define Stk_Size 128


OS_STK Start_TASK_STK[Stk_Size];
void start_task(void *pdata);

OS_STK Bluetooth_TASK_STK[Stk_Size];
void Bluetooth_task(void *pdata);

OS_STK Wifi_TASK_STK[Stk_Size];
void Wifi_task(void *pdata);

OS_STK Touch_TASK_STK[Stk_Size];
void Touch_task(void *pdata);

OS_STK Time_TASK_STK[Stk_Size];
void Time_task(void *pdata);

OS_STK T_and_H_TASK_STK[Stk_Size];
void T_and_H_task(void *pdata);




int main(void){

	
	Init_all();//��ʼ������
	
	OSInit();   
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&Start_TASK_STK[Stk_Size-1],P_Level_Start );//������ʼ����
	OSStart();

	

}



void start_task(void *pdata)  //������ʼ���� 
{
    OS_CPU_SR cpu_sr=0;
		pdata = pdata; 
  	OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)    
	
	OSTaskCreate(Bluetooth_task,(void *)0,(OS_STK*)&Bluetooth_TASK_STK[Stk_Size-1],P_Level_Bluetooth);
	OSTaskCreate(Wifi_task,(void *)0,(OS_STK*)&Wifi_TASK_STK[Stk_Size-1],P_Level_Wifi);
 	OSTaskCreate(Touch_task,(void *)0,(OS_STK*)&Touch_TASK_STK[Stk_Size-1],P_Level_Touch);						   
 	OSTaskCreate(Time_task,(void *)0,(OS_STK*)&Time_TASK_STK[Stk_Size-1],P_Level_Time);
	OSTaskCreate(T_and_H_task,(void *)0,(OS_STK*)&T_and_H_TASK_STK[Stk_Size-1],P_Level_T_and_H);
	
	
	OSTaskSuspend(P_Level_Start);	//������ʼ����.
	OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)	
	
	delay_ms(100);
	
}




void Bluetooth_task(void *pdata){ //�������Ʋ��֣�ͬʱ�ı�WiFi����ĵ�ַ������WiFi�����־λ�Լ�����ȷ��
	int i;
	int j;
	int k;

	while(1){  //��Ҫ�����豸����HC_Order��Execution�е�ֵ��10 and 0 to 9����Ϊ���趨�ı���
		
		//����������������оƬESP8266�Ĵ��ڽ��չ��ܣ���������������ƺ������ڴ�ģ��
		//ע�⣬����������������ͬʱ���ͣ������bug������
		
		//********************************Module 1, Bluetooth Control Center*******************//
		if((data_come_flag == 1)|(data_ESP_flag == 1)){      //�������н��յ�����ʱ����ʼ�жϲ�ִ������
			
			
			if(data_ESP_flag == 1){
				Data_ESP_deal();
				for(j=0;j<=19;j++){
					data_get[j] = data_ESP[j];
				}j=0;
			}
			
			//Send_HC_05(2,data_ESP);
			
			if(data_come_flag_next == 0){  //��Ϊ��������ʱ
				i = HC_Order();
				if(i == 10){Init_all();}    //��λȫ��ϵͳ
				if(i !=0){     //�������������Ч����i������0
					for(k=0;k<=4;k++){   //��ַ���һλ�������һ
						TX_ADDRESS[k] = TX_ADDRESS_ok[k];
					}
					TX_ADDRESS[4] = TX_ADDRESS_ok[4] + i;
					i=0;k=0;
				}
			}data_come_flag = 0;data_ESP_flag = 0;
			
		}
			
		  if(data_come_flag_next == 1){ //�μ�����ʱ(�����Ϊ�����ȴΣ���LED1���LEDΪ�������1Ϊ�μ�����)
				//Send_HC_05(2,data_get);
				j = HC_Order_inner();
				if(j == 10){}
				Execution(j);     //����ִ��ң��ָ��
				data_come_flag_next = 0;
			}
			else{
				for(j=0;j<=19;j++){  //��������
					data_get[j] = 0;
				}
				for(j=0;j<=39;j++){  //��������
					data_ESP[j] = 0;
				}
			}
			
		
		/////////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);  //Used for U/Cos system, 0.2S delay
		
	}
}

void Wifi_task(void *pdata){   //WiFi����ģ�飬(NRF24L01)
	while(1){
		//*******************************Module 2, Wifi Control *******************************//
		if(NRF24L01_RxPacket(get_wifi)==0){       //get from slave 
			
			WiFi_Operate();//��λ����һλ������ϵͳ��ţ��ڶ�λ��������ָ��
		}
		Wifi_send();  //Used to send message to slave,(Message get from bluetooth)
		//0-8;10-18��ַ
		
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);  //Used for U/Cos system, 0.2S delay

		
	}
}


void Touch_task(void *pdata){      //����Ļ��Ϊ12����м��
	short flag = 0;
	while(1){
		//**********************Module 3, Touch ****************************************************//
		//draw_P_lcd();

		flag = check_touch();
		if(flag != 0){
			page_operation(flag);
			LED_flash(6);
			delay_ms(200);
		}
		
		////////////////////////////////////////////////////////////////////////////////////
		
		else delay_ms(20);   //Used for U/Cos system, 0.02S delay
	}
	
}



void Time_task(void *pdata){  //ʵʱʱ����ʾ�Լ���Ϣ��ʾ����Ϣ��11��
	int rain_flag_buf; //���������ÿ�ζ�ˢ�����������Ļ
	rain_flag_buf = 0;
	
	while(1){
		//************************Module 3, Time display  ****************************************//
		if((page_flag == 0) | (page_flag == 1)){
			time_display();
		}
		else if(page_flag == 100){
			set_time_display();
		}

		
		else if(page_flag == 29){//��������
			if(rain_flag_buf != rain_flag){
				rain_flag_buf = rain_flag;
				LCD_Fill(15,50+75,250,50+105,0x5656);
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				if(rain_flag == 0){
					LCD_ShowString(25,50+85,200,1,16,"The Weather is Fine Now!!!");
				}
				else if(rain_flag == 1){
					LCD_ShowString(30+45,50+85,200,1,16,"Raining Now!!!");
				}
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;
			}
			
		}
		else if(page_flag == 28){//�¶�ʪ��
			
		}
		
		
		
		//////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);   //Used for U/Cos system, 0.2S delay
		
	}
	
}




void T_and_H_task(void *p){     //��ʪ������ͬʱ����ʪ��ҳ��ˢ�£�������Ϣ��ʾ����������ʾ��
	short Temp;
	short Humidity;
	u8 Check;
	short Temp_buf_1;
	short Humidity_buf_1;
	short Temp_buf_2;
	short Humidity_buf_2;
	
	while(1){
		if(DHT_READ(&Humidity,&Temp,&Check) == 0){    //ȡ���ݲ���ʾ����
			
			Humidity_buf_1 = Humidity/10;
			Humidity_buf_2 = Humidity - Humidity_buf_1*10;
			Temp_buf_1 = Temp/10;
			Temp_buf_2 = Temp - Temp_buf_1*10;
			if(page_flag == 28){
				
				//LCD_Fill(169,119,220,161,0x5656);
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				LCD_ShowString(25,100,130,1,20,"Temperature:");
				LCD_ShowNum(170,120,Temp_buf_1,2,16);
				LCD_ShowString(190,120,200,1,16,".");
				LCD_ShowNum(196,120,Temp_buf_2,1,16);
				LCD_ShowString(215,120,200,1,16,"`C");
				
				LCD_ShowString(25,140,150,1,20,"Humidity:");	
				LCD_ShowNum(170,160,Humidity_buf_1,2,16);	
				LCD_ShowString(190,160,200,1,16,".");
				LCD_ShowNum(196,160,Humidity_buf_2,1,16);
				LCD_ShowString(210,160,200,1,16,"%");
				
				
				
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;
				
				
			}			
			
		}
		delay_ms(500);
		delay_ms(500);//Used for U/Cos system, 1S delay
	}
	
}





























void Init_all(void)
{
	i = 0;
	data_come_flag = 0;
	data_come_flag_next = 0;
	wifi_flag = 0;
	for(i=0;i<=9;i++){
		
	} i = 0;
	
	
	delay_init();
	uart2_init(9600);
	uart_init(115200);
	LED_Init();
	LCD_Init();
	DHT_IO_Init();
	while(RTC_Init())		//RTC��ʼ��	��һ��Ҫ��ʼ���ɹ�
	{ 
		delay_ms(2);
	}	

	
	SPI1_Init();
	NRF24L01_Init();
	
	
	NRF24L01_Check();
	NRF24L01_RX_Mode();
	TP_Init();
	LCD_Clear(WHITE);
	
	while(ESP_Init(ssid_esp, password_esp) != 0){ //check ESP8266//test pass!!!
		delay_ms(200);
		LED_flash(6);
	}
	
	//HC_Check();  //�����������ģ���Ƿ��ܹ�ͨ�ţ����δ��ʼ������ͨ�ţ���LED��˸��������ʼ����
	//����HC_CHECK����֮��ᵼ������ͨ���쳣������������
	//RTC_Set(2017,5,15,21,16,0);
	
	//LCD INIT Module
	page_init();
	data_ESP_flag = 0; 
	
	
}




//			USART_SendData(USART1,i);		
//	while(1){     //���ʹ���������
//		DMA_UART(2,"hello_world\r\n");
//		delay_ms(500);
//	}




































