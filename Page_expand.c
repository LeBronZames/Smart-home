#include "stdlib.h"
#include "usart.h"
#include "delay.h"	 
#include "rtc.h"
#include "Page.h"
#include "Touch.h"
#include "HC-05.h"
#include "Page_expand.h"
#include "LDC.h"
#include "dma.h"


//输入法




u8 OK_in_2_flag = 0;  //用来二次确认, ==0表示按下ok键是用来确定字符 ， ==1表示用来确定所有输入


void page_operation_s_input_2(int flag){   //time set
	int k;
	int aaa;
	static u8 data_one;
	static u8 Cap_flag = 0;
	static u8 abc_flag[10]={0,0,0,0,0,0,0,0,0,0};
	
	
	
	k = 0; aaa = 1;
	
		switch(flag){
		case(1):{
			data_one = ' ';OK_in_2_flag = 0;
			break;
		}
		case(2):{
			switch(abc_flag[2]){
				case(0):{ abc_flag[2] = 1; if(Cap_flag == 0)data_one = 'a';else if(Cap_flag == 1)data_one = 'A'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;} //用于提示你输入什么
				case(1):{ abc_flag[2] = 2; if(Cap_flag == 0)data_one = 'b';else if(Cap_flag == 1)data_one = 'B'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[2] = 0; if(Cap_flag == 0)data_one = 'c';else if(Cap_flag == 1)data_one = 'C'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}

			}
			break;
		}
		case(3):{
			switch(abc_flag[3]){
				case(0):{ abc_flag[3] = 1; if(Cap_flag == 0)data_one = 'd';else if(Cap_flag == 1)data_one = 'D'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[3] = 2; if(Cap_flag == 0)data_one = 'e';else if(Cap_flag == 1)data_one = 'E'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[3] = 0; if(Cap_flag == 0)data_one = 'f';else if(Cap_flag == 1)data_one = 'F'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(4):{
			switch(abc_flag[4]){
				case(0):{ abc_flag[4] = 1; if(Cap_flag == 0)data_one = 'g';else if(Cap_flag == 1)data_one = 'G'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[4] = 2; if(Cap_flag == 0)data_one = 'h';else if(Cap_flag == 1)data_one = 'H'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[4] = 0; if(Cap_flag == 0)data_one = 'i';else if(Cap_flag == 1)data_one = 'I'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(5):{
			switch(abc_flag[5]){
				case(0):{ abc_flag[5] = 1; if(Cap_flag == 0)data_one = 'j';else if(Cap_flag == 1)data_one = 'J'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[5] = 2; if(Cap_flag == 0)data_one = 'k';else if(Cap_flag == 1)data_one = 'K'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[5] = 0; if(Cap_flag == 0)data_one = 'l';else if(Cap_flag == 1)data_one = 'L'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(6):{
			switch(abc_flag[6]){
				case(0):{ abc_flag[6] = 1; if(Cap_flag == 0)data_one = 'm';else if(Cap_flag == 1)data_one = 'M'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[6] = 2; if(Cap_flag == 0)data_one = 'n';else if(Cap_flag == 1)data_one = 'N'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[6] = 0; if(Cap_flag == 0)data_one = 'o';else if(Cap_flag == 1)data_one = 'O'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(7):{
			switch(abc_flag[7]){
				case(0):{ abc_flag[7] = 1; if(Cap_flag == 0)data_one = 'p';else if(Cap_flag == 1)data_one = 'P'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[7] = 2; if(Cap_flag == 0)data_one = 'q';else if(Cap_flag == 1)data_one = 'Q'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[7] = 3; if(Cap_flag == 0)data_one = 'r';else if(Cap_flag == 1)data_one = 'R'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(3):{ abc_flag[7] = 0; if(Cap_flag == 0)data_one = 's';else if(Cap_flag == 1)data_one = 'S'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(8):{
			switch(abc_flag[8]){
				case(0):{ abc_flag[8] = 1; if(Cap_flag == 0)data_one = 't';else if(Cap_flag == 1)data_one = 'T'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[8] = 2; if(Cap_flag == 0)data_one = 'u';else if(Cap_flag == 1)data_one = 'U'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[8] = 0; if(Cap_flag == 0)data_one = 'v';else if(Cap_flag == 1)data_one = 'V'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		case(9):{
			switch(abc_flag[9]){
				case(0):{ abc_flag[9] = 1; if(Cap_flag == 0)data_one = 'w';else if(Cap_flag == 1)data_one = 'W'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(1):{ abc_flag[9] = 2; if(Cap_flag == 0)data_one = 'x';else if(Cap_flag == 1)data_one = 'X'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(2):{ abc_flag[9] = 3; if(Cap_flag == 0)data_one = 'y';else if(Cap_flag == 1)data_one = 'Y'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
				case(3):{ abc_flag[9] = 0; if(Cap_flag == 0)data_one = 'z';else if(Cap_flag == 1)data_one = 'Z'; LCD_ShowString(80,275,200,1,16,&data_one);OK_in_2_flag = 0; break;}
			}
			break;
		}
		
		
		
		case(11):{
			if(Cap_flag == 0) {  //大小写切换
				Cap_flag = 1;
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				
				LCD_ShowString(20,50,200,1,16," ");
				LCD_ShowString(20+85,50,200,1,16,"ABC");
				LCD_ShowString(20+85+85,50,200,1,16,"DEF");
				LCD_ShowString(20,50+85,200,1,16,"GHI");
				LCD_ShowString(20+85,50+85,200,1,16,"JKL");
				LCD_ShowString(20+85+85,50+85,200,1,16,"MNO");
				LCD_ShowString(20,50+85+85,200,1,16,"PQRS");
				LCD_ShowString(20+85,50+85+85,200,1,16,"TUV");
				LCD_ShowString(20+85+85,50+85+85,200,1,16,"WXYZ");
				
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;
			}
			else if(Cap_flag == 1) {
				Cap_flag = 0;
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0x5656;
				
				LCD_ShowString(20,50,200,1,16," ");
				LCD_ShowString(20+85,50,200,1,16,"abc");
				LCD_ShowString(20+85+85,50,200,1,16,"def");
				LCD_ShowString(20,50+85,200,1,16,"ghi");
				LCD_ShowString(20+85,50+85,200,1,16,"jkl");
				LCD_ShowString(20+85+85,50+85,200,1,16,"mno");
				LCD_ShowString(20,50+85+85,200,1,16,"pqrs");
				LCD_ShowString(20+85,50+85+85,200,1,16,"tuv");
				LCD_ShowString(20+85+85,50+85+85,200,1,16,"wxyz");
				
				POINT_COLOR = 0x0000;
				BACK_COLOR = 0xffff;

			}
			
			
			
			break;
		}
		
		
		case(10):{    //BACK/DEL
			LCD_ShowString(80,275,200,1,16," ");//用于清空上一次的文字，为下一次做准备
			LCD_ShowString(80,295,200,10,16,"          "); //用于清空上一次的文字，为下一次做准备
			LCD_ShowString(80,295,200,10,16,data_input_abc[page_flag_buf - 10 - 1]);
			aaa = 1;
			for(k=0;k<=9;k++){    //<<DEL and <<BACK
			if(data_input_abc[page_flag_buf - 10 - 1][k] != 0)
				aaa = 0;
			}k=0;
			
			if(aaa == 1){
				if(page_flag_buf < 20){       //一个一个返回太麻烦了，我就这样搞，减轻工作量
					page_flag = 0; //主菜单
					page_init();
					
				}
				else if(page_flag_buf > 20){
					page_flag = 1; //第二个菜单栏
					page_two();
					
				}
			}
		
			else{
//				for(k=0;k<=9;k++){
//					data_input_abc[page_flag_buf - 10 - 1][k] = data_input_abc[page_flag_buf - 10 - 1][k+1];
//				}data_input_abc[page_flag_buf - 10 - 1][9] = 0; k = 0;
				for(k=0;k<=9;k++){              //判断最后一位在哪，然后删除
					if(data_input_abc[page_flag_buf - 10 - 1][k] == 0){
						data_input_abc[page_flag_buf - 10 - 1][k - 1] = 0;
						break;
					}
					if(k == 9){         //最后一位删除
						data_input_abc[page_flag_buf - 10 - 1][9] = 0;
					}
				}
				
				
				LCD_ShowString(80,275,200,1,16," ");//用于清空上一次的文字，为下一次做准备
				LCD_ShowString(80,295,200,10,16,"          "); //用于清空上一次的文字，为下一次做准备
				LCD_ShowString(80,295,200,10,16,data_input_abc[page_flag_buf - 10 - 1]);
					
				for(k=0;k<=9;k++){
					if(data_input_abc[page_flag_buf - 10 - 1][k] != 0){  //判断下一次显示del还是back
						LCD_ShowString(20,285,200,6,16,"<<DEL ");
						break;
					}
					else LCD_ShowString(20,285,200,6,16,"<<BACK");
				}
				
				
				
				
			}
			
			break;
		}
		
		
		case(12):{      //OK
			
			
			if(OK_in_2_flag == 1){      //即二次确定，以改变名字
				
				//***********************************************************//
				
				//Send_HC_05(2,data_input_abc[page_flag_buf - 10 - 1]);  //for test //字母出口！！！
				if(page_flag_buf <20){
					a[page_flag_buf - 10 - 1] = &data_input_abc[page_flag_buf - 10 - 1][0];
				}
				else if(page_flag_buf >20){
					b[page_flag_buf - 20 - 1] = &data_input_abc[page_flag_buf - 10 - 1][0];
				}
				
				
			
				if(page_flag_buf < 20 ){   //一个一个返回太麻烦了，我就这样搞，减轻工作量
					page_flag = 0; //主菜单
					page_init();
					
				}
				else if(page_flag_buf > 20){
					page_flag = 1; //第二个菜单栏
					page_two();
					
				}
				
				
				
				
				
				
				//******************************************************//
				
				
//				for(k=0;k<=13;k++){    //同时清零
//					data_input_abc[page_flag_buf - 10 - 1][k] = 0;
//				}
				
				OK_in_2_flag = 0;
				
				
				
			}
			
			else if(OK_in_2_flag == 0){  //确定字母
//				for(k=1;k<=9;k++){
//						data_input_abc[page_flag_buf - 10 - 1][k-1] = data_input_abc[page_flag_buf - 10 - 1][k];
//					}
//				data_input_abc[page_flag_buf - 10 - 1][9] = data_one; k = 0;
				for(k=0;k<=9;k++){
					if(data_input_abc[page_flag_buf - 10 - 1][k] == 0){
						data_input_abc[page_flag_buf - 10 - 1][k] = data_one;
						break;
					}
				}
				
				for(k=0;k<=9;k++){
					abc_flag[k] = 0;
				}
					
				OK_in_2_flag = 1;
				
				LCD_ShowString(80,275,200,1,16," ");//用于清空上一次的文字，为下一次做准备
				LCD_ShowString(80,295,200,10,16,"          "); //用于清空上一次的文字，为下一次做准备
				LCD_ShowString(80,295,200,10,16,data_input_abc[page_flag_buf - 10 - 1]); //输入的文字
				LCD_ShowString(20,285,200,6,16,"<<DEL "); //按下一次ok，下一次一定是del
			}
				
		}
			
			
			
			
			
			break;
	}
	
	
}



//***************************************************//


void page_input_2(void){
	u8 k;
	LCD_Clear(0xFFFF);//init lcd
	LCD_Fill(0,0,300,264,0x5656);
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0x5656;
	
	LCD_ShowString(20,50,200,1,16," ");
	LCD_ShowString(20+85,50,200,1,16,"abc");
	LCD_ShowString(20+85+85,50,200,1,16,"def");
	LCD_ShowString(20,50+85,200,1,16,"ghi");
	LCD_ShowString(20+85,50+85,200,1,16,"jkl");
	LCD_ShowString(20+85+85,50+85,200,1,16,"mno");
	LCD_ShowString(20,50+85+85,200,1,16,"pqrs");
	LCD_ShowString(20+85,50+85+85,200,1,16,"tuv");
	LCD_ShowString(20+85+85,50+85+85,200,1,16,"wxyz");
	
	POINT_COLOR = 0x0000;
	BACK_COLOR = 0xffff;
	
	draw_net(BLUE);
	
	

	
	
	LCD_ShowString(80,295,200,10,16,data_input_abc[page_flag_buf - 10 - 1]); //名字显示
	
	LCD_ShowString(20,285,200,6,16,"<<BACK");
	LCD_ShowString(180,285,200,6,16,"OK>>");
	for(k=0;k<=9;k++){
		if(data_input_abc[page_flag_buf - 10 - 1][k] != 0){  //判断下一次显示del还是back
			LCD_ShowString(20,285,200,6,16,"<<DEL ");
			break;
		}
		else LCD_ShowString(20,285,200,6,16,"<<BACK");
	}
}






















