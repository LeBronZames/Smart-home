#include "LDC.h"
#include "stdlib.h"
#include "usart.h"
#include "delay.h"	 
#include "rtc.h"
#include "Page.h"
#include "Touch.h"
#include "HC-05.h"
#include "Page_expand.h"
#include "ESP8266.h"
#include "Page_ESP.h"


//页面管理函数
void page_operation(int flag){  //页面执行函数，内个page_flag对于不同的操作
	switch(page_flag){  //每一个界面对应于不同flag（即区域点击）时的操作
		case(0):{   //初始化界面				
			page_operation_s_0(flag);
			break;
		}
		case(1):{   //第二菜单界面			
			page_operation_s_1(flag);
			break;
		}
		case(100):{  //page input_1
			page_operation_s_input_1(flag);
			break;
		}
		case(101):{  //page input_2
			page_operation_s_input_2(flag);
			break;
		}
		case(102):{  //page input_ESP
			page_operation_s_input_ESP(flag);
			break;
		}
		//********************** function *****************************//
		case(11):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(12):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(13):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(14):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(15):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(16):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(17):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(18):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(19):{   //function num	
			page_operation_ESP_set(flag);
			break;
		}
		///////////////////////////2//////////////////////
		case(21):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(22):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(23):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(24):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(25):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(26):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(27):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(28):{   //function num	
			page_operation_function(flag);
			break;
		}
		case(29):{   //function num	
			page_operation_function(flag);
			break;
		}
	}
	
}


//********************页面操作函数**************************//
void page_operation_s_0(int flag){
	switch(flag){
		case(1):{
			page_flag = 11; //function num
			page_Light();
			break;
		}
		case(2):{
			page_flag = 12; //function num
			page_CTRL();
			break;
		}
		case(3):{
			page_flag = 13; //function num
			page_function();
			break;
		}
		case(4):{
			page_flag = 14; //function num
			page_function();
			break;
		}
		case(5):{
			page_flag = 15; //function num
			page_function();
			break;
		}
		case(6):{
			page_flag = 16; //function num
			page_function();
			break;
		}
		case(7):{
			page_flag = 17; //function num
			page_function();
			break;
		}
		case(8):{
			page_flag = 18; //function num
			page_function();
			break;
		}
		case(9):{
			page_flag = 19; //function num
			page_input_ESP();
			break;
		}
		case(10):{
			
			break;
		}
		case(11):{
			
			page_flag_buf = page_flag;
			page_flag = 100; //数字输入
			page_input_1();
			break;
		}
		case(12):{
			page_flag = 1; //第二个菜单栏
			page_two();
			break;
		}
		
		
		
	}
	
	
}

void page_operation_s_1(int flag){
	switch(flag){
		case(1):{
			page_flag = 21; //function num
			page_function();
			break;
		}
		case(2):{
			page_flag = 22; //function num
			page_function();
			break;
		}
		case(3):{
			page_flag = 23; //function num
			page_function();
			break;
		}
		case(4):{
			page_flag = 24; //function num
			page_function();
			break;
		}
		case(5):{
			page_flag = 25; //function num
			page_function();
			break;
		}
		case(6):{
			page_flag = 26; //function num
			page_function();
			break;
		}
		case(7):{
			page_flag = 27; //function num
			page_function();
			break;
		}
		case(8):{
			page_flag = 28; //function num
			page_T_H();
			break;
		}
		case(9):{
			page_flag = 29; //function num
			page_Weather();
			break;
		}
		case(10):{
			page_flag = 0; //主菜单
			page_init();
			break;
		}
		case(11):{
			
			page_flag_buf = page_flag;
			page_flag = 100; //数字输入
			page_input_1();
			break;
		}
		case(12):{

			break;
		}
	}
	
}

//**************子页面操作函数**********************//
void page_operation_s_input_1(int flag){   //time set
	int k;
	int aaa;
	k = 0; aaa = 1;
		switch(flag){
		case(1):{
			time_set_input_1(flag);
			break;
		}
		case(2):{
			time_set_input_1(flag);
			break;
		}
		case(3):{
			time_set_input_1(flag);
			break;
		}
		case(4):{
			time_set_input_1(flag);
			break;
		}
		case(5):{
			time_set_input_1(flag);
			break;
		}
		case(6):{
			time_set_input_1(flag);
			break;
		}
		case(7):{
			time_set_input_1(flag);
			break;
		}
		case(8):{
			time_set_input_1(flag);
			break;
		}
		case(9):{
			time_set_input_1(flag);
			break;
		}
		case(10):{
			aaa = 1;
			for(k=0;k<=13;k++){    //<<DEL and <<BACK
			if(data_input_set[k] != 0)
				aaa = 0;
			}k=0;
			
			if(aaa == 1){
				if(page_flag_buf == 0){
					page_flag = 0; //主菜单
					page_init();
					
				}
				else if(page_flag_buf == 1){
					page_flag = 1; //第二个菜单栏
					page_two();
					
				}
			}
		
			else for(k=0;k<=13;k++){
				data_input_set[k] = data_input_set[k+1];
			}
			data_input_set[13] = 0; k = 0;
			break;
		}
		
		case(11):{
			time_set_input_1(0);
			break;
		}
		case(12):{
			RTC_Set(data_input_set[13]*1000+data_input_set[12]*100+data_input_set[11]*10+data_input_set[10],
			data_input_set[9]*10+data_input_set[8],
			data_input_set[7]*10+data_input_set[6],
			data_input_set[5]*10+data_input_set[4],
			data_input_set[3]*10+data_input_set[2],
			data_input_set[1]*10+data_input_set[0]);
			if(page_flag_buf == 0){
				page_flag = 0; //主菜单
				page_init();
				
			}
			else if(page_flag_buf == 1){
				page_flag = 1; //第二个菜单栏
				page_two();
				
			}
			
			for(k=0;k<=13;k++){    //同时清零
				data_input_set[k] = 0;
			}
			
			break;
		}
	}
	
}

void time_set_input_1(int i){
	int k=0;

	if(i != 10){
		for(k=13;k>=1;k--){
			data_input_set[k] = data_input_set[k-1];
		}
		data_input_set[0] = i; k = 0;
	}
	else if(i == 10){
	
	
		
	}

}

void page_operation_function(int flag){
	int k;
	k=0;
	if(flag == 10){  //返回菜单栏
		if(page_flag<=19){
			page_flag = 0; //主菜单
			page_init();
		}
		else if(page_flag>=20){
			page_flag = 1; //主菜单2
			page_two();
		}
		
	}
	
	else if(flag == 12){
			page_flag_buf = page_flag;
			page_flag = 101; //数字输入
			page_input_2();
	}
	
	else {      //用来发送WiFi给子系统
		if(page_flag <=27){

				for(k=0;k<=4;k++){   //地址最后一位随命令加
					TX_ADDRESS[k] = TX_ADDRESS_ok[k];
				}
				TX_ADDRESS[4] = TX_ADDRESS_ok[4] + page_flag -10 ;
				k=0;
			}
			
			Execution(flag);     //用来执行遥控指令
	}
}
	
	




/////////////////////////页面画面函数*********************************//

void page_init(void){
	
	LCD_Clear(0xFFFF);//init lcd
	ico();
	ico_name_all();
	draw_line(265);
	
	
	LCD_Fill(0,266,300,366,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	
	LCD_ShowString(180,285,200,6,16,"NEXT>>");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
}

void page_two(void){
	LCD_Clear(0xFFFF);//init lcd
	ico_2();
	ico_name_all();
	draw_line(265);
	
	
	LCD_Fill(0,266,300,366,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(20,285,200,6,16,"<<BACK");
	
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
}

void page_input_1(void){
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(30,50,200,1,16,"1");
	LCD_ShowString(30+85,50,200,1,16,"2");
	LCD_ShowString(30+85+85,50,200,1,16,"3");
	LCD_ShowString(30,50+85,200,1,16,"4");
	LCD_ShowString(30+85,50+85,200,1,16,"5");
	LCD_ShowString(30+85+85,50+85,200,1,16,"6");
	LCD_ShowString(30,50+85+85,200,1,16,"7");
	LCD_ShowString(30+85,50+85+85,200,1,16,"8");
	LCD_ShowString(30+85+85,50+85+85,200,1,16,"9");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	draw_net(BLUE);

	
	
	LCD_ShowString(20,285,200,6,16,"<<DEL");
	LCD_ShowString(180,285,200,6,16,"OK>>");
}


void page_function(void){
	
	int i;
	i = page_flag -10 - 1;
	
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(30,50,200,1,16,"1");
	LCD_ShowString(30+85,50,200,1,16,"2");
	LCD_ShowString(30+85+85,50,200,1,16,"3");
	LCD_ShowString(30,50+85,200,1,16,"4");
	LCD_ShowString(30+85,50+85,200,1,16,"5");
	LCD_ShowString(30+85+85,50+85,200,1,16,"6");
	LCD_ShowString(30,50+85+85,200,1,16,"7");
	LCD_ShowString(30+85,50+85+85,200,1,16,"8");
	LCD_ShowString(30+85+85,50+85+85,200,1,16,"9");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	draw_net(BLUE);

	LCD_ShowString(20,285,200,6,16,"<<BACK");
	if(i<=9)
	LCD_ShowString(170,285,200,6,16,aa[i]);    //显示控制当前的模块
	else LCD_ShowString(170,285,200,6,16,bb[i-10]);    //显示控制当前的模块

}


void page_Weather(void){   //天气界面，page_flag = 29;

int i;
	i = page_flag -10 - 1;
	
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
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
	

	draw_line(265);
	LCD_ShowString(20,285,200,6,16,"<<BACK");
	if(i<=9)
	LCD_ShowString(150,285,200,6,16,aa[i]);    //显示控制当前的模块
	else LCD_ShowString(150,285,200,6,16,bb[i-10]);    //显示控制当前的模块
}

void page_T_H(void){   //温湿度界面，page_flag = 28;

int i;
	i = page_flag -10 - 1;
	
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_Fill(15,50+75,250,161,0x5656);
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	LCD_ShowString(25,100,130,1,16,"Temperature:");
	LCD_ShowString(25,140,150,1,16,"Humidity:");				
			
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	

	draw_line(265);
	LCD_ShowString(20,285,200,6,16,"<<BACK");
	if(i<=9)
	LCD_ShowString(150,285,200,6,16,aa[i]);    //显示控制当前的模块
	else LCD_ShowString(150,285,200,6,16,bb[i-10]);    //显示控制当前的模块
}





void page_Light(void){     //灯模块，page_flag = 1;
	int i;
	i = page_flag -10 - 1;
	
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(10,50,200,1,12,"AUTO/MANUAL");
	LCD_ShowString(20+85,50,200,1,16,"ON_1");
	LCD_ShowString(20+85+85,50,200,1,16,"ON_2");
	LCD_ShowString(20,50+85,200,1,16,"ON_3");
	LCD_ShowString(20+85,50+85,200,1,16,"OFF");
	LCD_ShowString(30+85+85,50+85,200,1,16,"6");
	LCD_ShowString(30,50+85+85,200,1,16,"7");
	LCD_ShowString(30+85,50+85+85,200,1,16,"8");
	LCD_ShowString(30+85+85,50+85+85,200,1,16,"9");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	draw_net(BLUE);

	LCD_ShowString(20,285,200,6,16,"<<BACK");
	if(i<=9)
	LCD_ShowString(170,285,200,6,16,aa[i]);    //显示控制当前的模块
	else LCD_ShowString(170,285,200,6,16,bb[i-10]);    //显示控制当前的模块
	
	
	
	LCD_ShowString(80,275,200,6,16,"Light");
	LCD_ShowNum(80,295,light_lex,5,16);
		if(get_wifi[3] == 1){
			LCD_ShowString(140,285,200,1,16,"A");
		}
		else if(get_wifi[3] == 0){
			LCD_ShowString(140,285,200,1,16,"M");
		}

}

void page_CTRL(void){     //万能遥控器模块
	
	int i;
	i = page_flag -10 - 1;
	
	
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(20,50,200,1,16,"LEARN");
	LCD_ShowString(20+85,50,200,1,16,"ON");
	LCD_ShowString(20+85+85,50,200,1,16,"OFF");
	LCD_ShowString(30,50+85,200,1,16,"+");
	LCD_ShowString(30+85,50+85,200,1,16,"-");
	LCD_ShowString(25+85+85,50+85,200,1,16,"F1");
	LCD_ShowString(25,50+85+85,200,1,16,"F2");
	LCD_ShowString(25+85,50+85+85,200,1,16,"F3");
	LCD_ShowString(25+85+85,50+85+85,200,1,16,"F4");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	draw_net(BLUE);

	LCD_ShowString(20,285,200,6,16,"<<BACK");
	if(i<=9)
	LCD_ShowString(170,285,200,6,16,aa[i]);    //显示控制当前的模块
	else LCD_ShowString(170,285,200,6,16,bb[i-10]);    //显示控制当前的模块

	
		if(get_wifi[1] == 0){  //正常模式
			LCD_ShowString(100,285,200,6,16,"Normal");

		}
		else if(get_wifi[1] == 1){  //学习模式
			LCD_ShowString(100,285,200,6,16,"LEARN ");
		}
	
	
}


