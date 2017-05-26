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



u8 data_ESP[40]; //ESP8266接收数据
u8 data_ESP_flag;

u8 data_get[20];  //最高20字符的接收蓝牙端数据缓存
u8 data_come_flag; //UART2接收到蓝牙数据的Flag
u8 data_come_flag_next;  //次级命令flag
int i;
u8 get_wifi[32];  //在本设计中，NRF简称WiFi
u8 sent_wifi[32];
u8 wifi_flag;
int page_flag = 0;  //判断页面在哪	
int page_flag_buf = 0;//用于返回菜单
u8 data_input_set[14];  //用于存储设置时间信息
u8 data_input_abc[20][10]; //用于存储名称信息（字母）

char ssid_esp[10] = {"lv"};
char password_esp[10] = {"12121212"};


char *a[9] = {"Light","CTRL","CCC","DDD","EEE","FFF","GGG","HHH","ESP8266"};
char *b[9] = {"JJJ","KKK","LLL","MMM","NNN","OOO","PPP","Temp-Humi","Weather"};
u8 aa[9][10];
u8 bb[9][10];

extern const u8 mobilephone_bmp[];

extern u8 rain_flag;  //1 is raining
	
	

u8 TX_ADDRESS_ok[5]={0x1A,0x3B,0x5C,0x7D,0x9E};//基地址
u8 RX_ADDRESS_ok[5]={0x1A,0x3B,0x5C,0x7D,0x9E};

u8 TX_ADDRESS[5]={0x1A,0x3B,0x5C,0x7D,0x9E}; //可变化发送地址
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

	
	Init_all();//初始化程序
	
	OSInit();   
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&Start_TASK_STK[Stk_Size-1],P_Level_Start );//创建起始任务
	OSStart();

	

}



void start_task(void *pdata)  //创建起始任务 
{
    OS_CPU_SR cpu_sr=0;
		pdata = pdata; 
  	OS_ENTER_CRITICAL();			//进入临界区(无法被中断打断)    
	
	OSTaskCreate(Bluetooth_task,(void *)0,(OS_STK*)&Bluetooth_TASK_STK[Stk_Size-1],P_Level_Bluetooth);
	OSTaskCreate(Wifi_task,(void *)0,(OS_STK*)&Wifi_TASK_STK[Stk_Size-1],P_Level_Wifi);
 	OSTaskCreate(Touch_task,(void *)0,(OS_STK*)&Touch_TASK_STK[Stk_Size-1],P_Level_Touch);						   
 	OSTaskCreate(Time_task,(void *)0,(OS_STK*)&Time_TASK_STK[Stk_Size-1],P_Level_Time);
	OSTaskCreate(T_and_H_task,(void *)0,(OS_STK*)&T_and_H_TASK_STK[Stk_Size-1],P_Level_T_and_H);
	
	
	OSTaskSuspend(P_Level_Start);	//挂起起始任务.
	OS_EXIT_CRITICAL();				//退出临界区(可以被中断打断)	
	
	delay_ms(100);
	
}




void Bluetooth_task(void *pdata){ //蓝牙控制部分，同时改变WiFi传输的地址，并将WiFi传输标志位以及数据确定
	int i;
	int j;
	int k;

	while(1){  //如要增加设备，将HC_Order与Execution中的值（10 and 0 to 9）改为可设定的变量
		
		//在内新增加物联网芯片ESP8266的串口接收功能，即蓝牙与网络控制合用在于此模块
		//注意，如果蓝牙与网络控制同时发送，会出现bug！！！
		
		//********************************Module 1, Bluetooth Control Center*******************//
		if((data_come_flag == 1)|(data_ESP_flag == 1)){      //当蓝牙有接收到数据时，开始判断并执行命令
			
			
			if(data_ESP_flag == 1){
				Data_ESP_deal();
				for(j=0;j<=19;j++){
					data_get[j] = data_ESP[j];
				}j=0;
			}
			
			//Send_HC_05(2,data_ESP);
			
			if(data_come_flag_next == 0){  //当为初级命令时
				i = HC_Order();
				if(i == 10){Init_all();}    //复位全部系统
				if(i !=0){     //当命令传过来才有效，即i不等于0
					for(k=0;k<=4;k++){   //地址最后一位随命令加一
						TX_ADDRESS[k] = TX_ADDRESS_ok[k];
					}
					TX_ADDRESS[4] = TX_ADDRESS_ok[4] + i;
					i=0;k=0;
				}
			}data_come_flag = 0;data_ESP_flag = 0;
			
		}
			
		  if(data_come_flag_next == 1){ //次级命令时(命令分为两个等次，如LED1命令，LED为初级命令，1为次级命令)
				//Send_HC_05(2,data_get);
				j = HC_Order_inner();
				if(j == 10){}
				Execution(j);     //用来执行遥控指令
				data_come_flag_next = 0;
			}
			else{
				for(j=0;j<=19;j++){  //否则清零
					data_get[j] = 0;
				}
				for(j=0;j<=39;j++){  //否则清零
					data_ESP[j] = 0;
				}
			}
			
		
		/////////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);  //Used for U/Cos system, 0.2S delay
		
	}
}

void Wifi_task(void *pdata){   //WiFi传输模块，(NRF24L01)
	while(1){
		//*******************************Module 2, Wifi Control *******************************//
		if(NRF24L01_RxPacket(get_wifi)==0){       //get from slave 
			
			WiFi_Operate();//两位，第一位标明子系统标号，第二位标明操作指令
		}
		Wifi_send();  //Used to send message to slave,(Message get from bluetooth)
		//0-8;10-18地址
		
		
		
		////////////////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);  //Used for U/Cos system, 0.2S delay

		
	}
}


void Touch_task(void *pdata){      //将屏幕分为12块进行检测
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



void Time_task(void *pdata){  //实时时间显示以及信息显示（信息区11）
	int rain_flag_buf; //有这个不用每次都刷新下雨界面屏幕
	rain_flag_buf = 0;
	
	while(1){
		//************************Module 3, Time display  ****************************************//
		if((page_flag == 0) | (page_flag == 1)){
			time_display();
		}
		else if(page_flag == 100){
			set_time_display();
		}

		
		else if(page_flag == 29){//下雨天晴
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
		else if(page_flag == 28){//温度湿度
			
		}
		
		
		
		//////////////////////////////////////////////////////////////////////////////////////
		delay_ms(200);   //Used for U/Cos system, 0.2S delay
		
	}
	
}




void T_and_H_task(void *p){     //温湿度任务（同时兼温湿度页面刷新，不用信息显示的任务来显示）
	short Temp;
	short Humidity;
	u8 Check;
	short Temp_buf_1;
	short Humidity_buf_1;
	short Temp_buf_2;
	short Humidity_buf_2;
	
	while(1){
		if(DHT_READ(&Humidity,&Temp,&Check) == 0){    //取数据并显示出来
			
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
	while(RTC_Init())		//RTC初始化	，一定要初始化成功
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
	
	//HC_Check();  //用来检测蓝牙模块是否能够通信，如果未初始化或不能通信，则LED闪烁（按键初始化）
	//加上HC_CHECK函数之后会导致蓝牙通信异常！！！！！！
	//RTC_Set(2017,5,15,21,16,0);
	
	//LCD INIT Module
	page_init();
	data_ESP_flag = 0; 
	
	
}




//			USART_SendData(USART1,i);		
//	while(1){     //发送代码至主机
//		DMA_UART(2,"hello_world\r\n");
//		delay_ms(500);
//	}




































