#include "TFT_LCD.h"




int TFT_init(void)
{
	TFT_io_init();
	
	
	
	TFT_WRITE(0xCF,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xC1,1);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0xED,0);
	TFT_WRITE(0x64,1);
	TFT_WRITE(0x03,1);
	TFT_WRITE(0x12,1);
	TFT_WRITE(0x81,1);
	TFT_WRITE(0xE8,0);
	TFT_WRITE(0x85,1);
	TFT_WRITE(0x10,1);
	TFT_WRITE(0x7A,1);
	TFT_WRITE(0xCB,0);
	TFT_WRITE(0x39,1);
	TFT_WRITE(0x2C,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x34,1);
	TFT_WRITE(0x02,1);
	TFT_WRITE(0xF7,0);
	TFT_WRITE(0x20,1);
	TFT_WRITE(0xEA,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xc0,0);
	TFT_WRITE(0x1b,1);
	TFT_WRITE(0xc1,1);
	TFT_WRITE(0x01,1);
	TFT_WRITE(0xc5,0);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0x30,1);
	TFT_WRITE(0xc7,0);
	TFT_WRITE(0xb7,1);
	
	TFT_WRITE(0x36,0);
	TFT_WRITE(0x48,1);
	TFT_WRITE(0x3a,0);
	TFT_WRITE(0x55,1);
	TFT_WRITE(0xb1,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x1a,1);
	TFT_WRITE(0xb6,0);
	TFT_WRITE(0x0a,1);
	TFT_WRITE(0xa2,1);
	TFT_WRITE(0xf2,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x26,0);
	TFT_WRITE(0x01,1);
	TFT_WRITE(0xe0,0);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x2a,1);
	TFT_WRITE(0x28,1);
	TFT_WRITE(0x08,1);
	TFT_WRITE(0x0e,1);
	TFT_WRITE(0x08,1);
	TFT_WRITE(0x54,1);
	TFT_WRITE(0xa9,1);
	TFT_WRITE(0x43,1);
	TFT_WRITE(0x0a,1);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x15,1);
	TFT_WRITE(0x17,1);
	TFT_WRITE(0x07,1);
	TFT_WRITE(0x11,1);
	TFT_WRITE(0x06,1);
	TFT_WRITE(0x2b,1);
	TFT_WRITE(0x56,1);
	TFT_WRITE(0x3c,1);
	TFT_WRITE(0x05,1);
	TFT_WRITE(0x10,1);
	TFT_WRITE(0x0f,1);
	TFT_WRITE(0x3f,1);
	TFT_WRITE(0x0f,1);
	
	TFT_WRITE(0x2b,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x2a,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xe1,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x2a,0);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0x00,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0xef,1);
	TFT_WRITE(0x11,0);
	
	//delay_ms(10);
	
	TFT_WRITE(0x29,0);
	TFT_WRITE(0x36,0);
	TFT_WRITE(0x6c,1);
	TFT_WRITE(0x2c,0);
	
	
	TFT_clear(0xffff);
	return 1;
	

	
}


void TFT_test(void)
{
	
	TFT_WRITE_16(0xbb25,1);
	
}



void TFT_io_init(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	 GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;			
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		
   GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	 GPIO_SetBits(GPIOB,GPIO_Pin_All);						 //输出高
	
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6 ;				
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		
   GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIO
	 GPIO_SetBits(GPIOC,GPIO_Pin_9 | GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6);						 //输出高
	
	
	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;				 //PC13 端口配置
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
   GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOc.13
   GPIO_SetBits(GPIOC,GPIO_Pin_10);						 //PC.13 输出高
	
	
}


void TFT_WRITE(u8 data_reg, int flag)
{
	RD_SET;
	CS_CLR;
	if(flag == 0)
	{
	RS_CLR;
	}
	else if(flag == 1) //rs是1为数据
	{
		RS_SET;
	}
	WR_CLR;
	GPIO_SetBits(GPIOB,(data_reg & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data_reg) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
}
/*
void TFT_data(u8 data_reg)
{
	RD_SET;
	CS_CLR;
	RS_SET;
	WR_CLR;
	GPIO_SetBits(GPIOB,(data_reg & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data_reg) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
}
*/

void TFT_WRITE_16(u16 data, int flag)
{
	RD_SET;
	CS_CLR;
	if(flag == 0)
	{
	RS_CLR;
	}
	else if(flag == 1) //rs是1为数据
	{
		RS_SET;
	}
	WR_CLR;
	GPIO_SetBits(GPIOB,(data & 0xFFFF));//DATAOUT(data);
	GPIO_ResetBits(GPIOB,((~data) & 0xFFFF));//DATAOUT(data);
	WR_SET;
	
	
}





int draw_point(u16 a, u16 b, u16 color) //四个像素为一个点
{
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((a>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((b>>8), 1);TFT_WRITE((b&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a+1)>>8), 1);TFT_WRITE(((a+1)&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b)>>8), 1);TFT_WRITE((b&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a)>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b+1)>>8), 1);TFT_WRITE(((b+1)&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//***************************************
	TFT_WRITE(0x2b, 0);
	TFT_WRITE(((a+1)>>8), 1);TFT_WRITE(((a+1)&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE(((b+1)>>8), 1);TFT_WRITE(((b+1)&0XFF),1);
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	
	return 1;
}



int draw_point_one(u16 a, u16 b, u16 color)
{
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((a>>8), 1);TFT_WRITE((a&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((b>>8), 1);TFT_WRITE((b&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	TFT_WRITE_16(color, 1);
	//delay_us(10);
	//***************************************
	return 1;
}




void TFT_clear(u16 color)
{
	int a;
	a = 96800;
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	
	for(;a >=0;a--)
	{
		TFT_WRITE_16(color, 1);
	}
}




void TFT_clear_num_1(void)
{
	int x; 
	int y; x=30;y=190;
	
		
	for(x=30;x<=70;x++)
	{
		y = 190;
		TFT_WRITE(0x2b, 0);
		TFT_WRITE((x>>8), 1);TFT_WRITE((x&0XFF),1);
		
		TFT_WRITE(0x2a, 0);
		TFT_WRITE((y>>8), 1);TFT_WRITE((y&0XFF),1);
		
		TFT_WRITE(0x2c, 0);
		for(y=190;y<=230;y++)
		{
			TFT_WRITE_16(0xffff, 1);
		}
	
	}
	  
}

void TFT_clear_num_2(void)
{
	int x; 
	int y; x=160;y=80;
	
		
	for(x=140;x<=210;x++)
	{
		y = 40;
		TFT_WRITE(0x2b, 0);
		TFT_WRITE((x>>8), 1);TFT_WRITE((x&0XFF),1);
		
		TFT_WRITE(0x2a, 0);
		TFT_WRITE((y>>8), 1);TFT_WRITE((y&0XFF),1);
		
		TFT_WRITE(0x2c, 0);
		for(y=40;y<=80;y++)
		{
			TFT_WRITE_16(0xffff, 1);
		}
	
	}
	  
}



void TFT_background(u16 color)
{
	int a;
	int x;
	int y;x=10;y=125;
	a = 96800;
	TFT_WRITE(0x2b, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2a, 0);
	TFT_WRITE((0>>8), 1);TFT_WRITE((0&0XFF),1);
	
	TFT_WRITE(0x2c, 0);
	
	for(;a >=0;a--)
	{
		TFT_WRITE_16(color, 1);
	}
	
	for(y=125;y>=100;y--)
	{
		for(x=10;x<=230;x++)
		{
			draw_point_one(x, y, RGB888ToRGB565(c10 ,1));
		}
	
	}
}


char number_tran_to_display_ge(int cnt)
{
	int a;
	int b;
	b = cnt/10;
	a = cnt - (b*10) ;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
		default:
			{
				return '0';
			}
	}
	//return 0;
}
char number_tran_to_display_shi(int cnt)
{
	
	int a;
	a = cnt/10 - (cnt/100)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
		default:
			{
				return '0';
			}
	}
	//return 0;
	
	
}
	

char number_tran_to_display_bai(int cnt)
{
	
	int a;
	a = cnt/100-(cnt/1000)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
		default:
			{
				return '0';
			}
	}
	//return 0;
	
	
}


char number_tran_to_display_qian(int cnt)
{
	
	int a;
	a = cnt/1000-(cnt/10000)*10;
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
		default:
			{
				return '0';
			}
	}
	//return 0;
	
	
}


char number_tran_to_display_wan(int cnt)
{
	
	int a;
	
	a = cnt/10000;
	
	switch(a)
	{
		case 9:
		{
			return '9';
			//break;
		}
		case 8:
		{
			return '8';
			//break;
		}
		case 7:
		{
			return '7';
			//break;
		}
		case 6:
		{
			return '6';
			//break;
		}
		case 5:
		{
			return '5';
			//break;
		}
		case 4:
		{
			return '4';
			//break;
		}
		case 3:
		{
			return '3';
			//break;
		}
		case 2:
		{
			return '2';
			//break;
		}
		case 1:
		{
			return '1';
			//break;
		}
		case 0:
		{
			return '0';
			//break;
		}
		default:
			{
				return '0';
			}
		}
	//return 0;
	
	
}



char number_tran_to_display_eight(int cnt)
{
	int a;
	a = cnt/(16*16*16*16*16*16*16);
	switch(a)
	{
		case 15:		
			return '9';
		case 14:		
			return '9';
		case 13:		
			return '9';
		case 12:		
			return '9';
		case 11:		
			return '9';
		case 10:		
			return '9';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}

char number_tran_to_display_seven(int cnt)
{
	int a;
	a = cnt/(16*16*16*16*16*16) - (cnt/(16*16*16*16*16*16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}
  
char number_tran_to_display_six(int cnt)
{
	int a;
	a = cnt/(16*16*16*16*16) - (cnt/(16*16*16*16*16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}

char number_tran_to_display_five(int cnt)
{
	int a;
	a = cnt/(16*16*16*16) - (cnt/(16*16*16*16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}

char number_tran_to_display_four(int cnt)
{
	int a;
	a = cnt/(16*16*16) - (cnt/(16*16*16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}

char number_tran_to_display_three(int cnt)
{
	int a;
	a = cnt/(16*16) - (cnt/(16*16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}

char number_tran_to_display_two(int cnt)
{
	int a;
	a = cnt/(16) - (cnt/(16*16))*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
//	return 0;
}

char number_tran_to_display_one(int cnt)
{
	int a;
	a = cnt - (cnt/16)*16;
	switch(a)
	{
		case 15:		
			return 'f';
		case 14:		
			return 'e';
		case 13:		
			return 'd';
		case 12:		
			return 'c';
		case 11:		
			return 'b';
		case 10:		
			return 'a';
		case 9:		
			return '9';
		case 8:
			return '8';
		case 7:
			return '7';
		case 6:
			return '6';
		case 5:
			return '5';
		case 4:
			return '4';
		case 3:
			return '3';
		case 2:
			return '2';
		case 1:
			return '1';
		case 0:
			return '0';
		default:
				return '0';
		}
	//return 0;
}


u16 RGB888ToRGB565(unsigned int n888Color ,int flag)  
{  
	if(flag == 0)
	{
		return 0xffff;
	}
	else
	{
    unsigned short n565Color = 0;  
  
    
    unsigned char cRed   = (n888Color & RGB888_RED)   >> 19;  
    unsigned char cGreen = (n888Color & RGB888_GREEN) >> 10;  
    unsigned char cBlue  = (n888Color & RGB888_BLUE)  >> 3;  
  
  
    n565Color = (cRed << 11) + (cGreen << 5) + (cBlue << 0);  
		
    return n565Color;  
	}
} 



void draw_word(int x, int y, char word, u16 color)
{
	int a;
	int b;
	a = x;
	b = y;
	switch(word)
	{
		
		case 'A':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			a = x + 12;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		
		case 'F':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		
		case 'C':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 26;
			draw_point(a, b, color);
			break;
		}
		
		case 'E':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 26;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		
		
		
		case 'I':
		{
			a = x + 6;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			break;
		}
		case 'O':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			a = x + 12;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			break;
		}
		
		
		
		case 'M':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x + 12;
			draw_across(a, b, color);
			a = x;
			b = y;
			draw_vertical(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical(a, b, color);
			a = x + 24;
			b = y;
			draw_vertical(a, b, color);
			break;
		}
		
		case 'N':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y;
			draw_vertical(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical(a, b, color);
			break;
		}
		
		case 'R':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			a = x + 12;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			b = b + 2;
			a = a + 2;
			draw_point(a, b, color);
			a = a + 2;
			draw_point(a, b, color);
			a = a + 2;
			draw_point(a, b, color);
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		
		case 'T':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);

			a = x + 6;
			b = y;
			draw_vertical(a, b, color);
			break;
		}	
		case 'S':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			break;
		}
	}
}


void draw_number(int x, int y, char number, u16 color)
{
	int a,b;
	switch(number)
	{
		case '0':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			a = x + 12;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			break;
		}
		
		case '1':
		{
			a = x + 6;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			break;
		}
		
		case '2':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x;
			b = y - 26;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y - 12;
			draw_vertical_short(a, b, color);
			break;
		}
		
		case '3':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical(a, b, color);
			break;
		}
		
		case '4':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical(a, b, color);
			break;
		}
		case '5':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			break;
		}
		case '6':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_vertical_short(a, b, color);
			break;
		}
		case '7':
		{
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical(a, b, color);
			break;
		}
		case '8':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical_short(a, b, color);
			break;
		}
		case '9':
		{
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y;
			draw_across(a, b, color);
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			a = x + 12;
			b = y;
			draw_vertical_short(a, b, color);
			break;
		}
		case 'a':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			a = x + 12;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		case 'b':
		{
			
			a = x;
			b = y;
			draw_vertical_short(a, b, color);
			a = x;
			b = y - 12;
			draw_vertical_short(a, b, color);
			/*a = x;
			b = y;
			draw_across(a, b, color);*/
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			break;
		}
		case 'c':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 26;
			draw_point(a, b, color);
			break;
		}
		case 'd':
		{
			
			a = x + 12;
			b = y;
			draw_vertical_short(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_vertical_short(a, b, color);
			/*a = x;
			b = y;
			draw_across(a, b, color);*/
			a = x;
			b = y - 12;
			draw_across(a, b, color);
			a = x ;
			b = y - 12;
			draw_vertical_short(a, b, color);
			a = x ;
			b = y - 26;
			draw_across(a, b, color);
			break;
		}
		case 'e':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 26;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 26;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
		case 'f':
		{
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}
			
			
			a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
			
			a = x + 2;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 4;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 6;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 8;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 10;
			b = y - 12;
			draw_point(a, b, color);
			a = x + 12;
			b = y - 12;
			draw_point(a, b, color);
			break;
		}
	}
	
}


void draw_across(int x, int y, u16 color)
{
	int a;
	int b;
	    a = x;
			b = y;
			draw_point(a, b, color);
	    a = x + 2;
			b = y;
			draw_point(a, b, color);
			a = x + 4;
			b = y;
			draw_point(a, b, color);
			a = x + 6;
			b = y;
			draw_point(a, b, color);
			a = x + 8;
			b = y;
			draw_point(a, b, color);
			a = x + 10;
			b = y;
			draw_point(a, b, color);
			a = x + 12;
			b = y;
			draw_point(a, b, color);
}

void draw_vertical(int x, int y, u16 color)
{
	int a,b;
	
			a = x;
			b = y;
			for(;b>y-28;b=b-2)
			{
				draw_point(a, b, color);
			}

}

void draw_vertical_short(int x, int y, u16 color)
{
	int a,b;
	
			a = x;
			b = y;
			for(;b>y-14;b=b-2)
			{
				draw_point(a, b, color);
			}

}


void num_16_for_test(int x, int y, int z, int a, int b, int c)
{
	TFT_clear(0xffff);
		
		
		draw_number(10, 300, number_tran_to_display_four(x), 0x5656);
		draw_number(10+20, 300, number_tran_to_display_three(x), 0x5656);  //屏幕左上
		draw_number(10+20+20, 300, number_tran_to_display_two(x), 0x5656);

		draw_number(10+20+20+20, 300, number_tran_to_display_one(x), 0x5656);
	/*
		draw_number(10+20+20+20+20, 300, number_tran_to_display_four(x), 0x5656);
		draw_number(10+20+20+20+20+20, 300, number_tran_to_display_three(x), 0x5656);
		draw_number(10+20+20+20+20+20+20, 300, number_tran_to_display_two(x), 0x5656);
		draw_number(10+20+20+20+20+20+20+20, 300, number_tran_to_display_one(x), 0x5656);*/
		
		draw_number(10, 200, number_tran_to_display_four(y), 0x5656);  //屏幕中
		draw_number(10+20, 200, number_tran_to_display_three(y), 0x5656);
		draw_number(10+20+20, 200, number_tran_to_display_two(y), 0x5656);
		draw_number(10+20+20+20, 200, number_tran_to_display_one(y), 0x5656);
		/*draw_number(10+20+20+20+20, 200, number_tran_to_display_four(y), 0x5656);
		draw_number(10+20+20+20+20+20, 200, number_tran_to_display_three(y), 0x5656);
		draw_number(10+20+20+20+20+20+20, 200, number_tran_to_display_two(y), 0x5656);
		draw_number(10+20+20+20+20+20+20+20, 200, number_tran_to_display_one(y), 0x5656);*/
	
		draw_number(10, 90, number_tran_to_display_four(z), 0x5656);  //屏幕下
		draw_number(10+20, 90, number_tran_to_display_three(z), 0x5656);
		draw_number(10+20+20, 90, number_tran_to_display_two(z), 0x5656);
		draw_number(10+20+20+20, 90, number_tran_to_display_one(z), 0x5656);
		/*draw_number(10+20+20+20+20, 90, number_tran_to_display_four(z), 0x5656);
		draw_number(10+20+20+20+20+20, 90, number_tran_to_display_three(z), 0x5656);
		draw_number(10+20+20+20+20+20+20, 90, number_tran_to_display_two(z), 0x5656);
		draw_number(10+20+20+20+20+20+20+20, 90, number_tran_to_display_one(z), 0x5656);*/
	/*
		draw_number(30+20+20+25+40, 225, number_tran_to_display_wan(a), 0x5656);  //屏幕右上
		draw_number(30+20+20+20+25+40, 225, number_tran_to_display_qian(a), 0x5656);
		draw_number(30+20+20+20+25+40+20, 225, number_tran_to_display_bai(a), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 225, number_tran_to_display_shi(a), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 225, number_tran_to_display_ge(a), 0x5656);
		
		draw_number(30+20+20+25+40, 145, number_tran_to_display_wan(b), 0x5656);  //屏幕右中
		draw_number(30+20+20+20+25+40, 145, number_tran_to_display_qian(b), 0x5656);
		draw_number(30+20+20+20+25+40+20, 145, number_tran_to_display_bai(b), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 145, number_tran_to_display_shi(b), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 145, number_tran_to_display_ge(b), 0x5656);
		
		draw_number(30+20+20+25+40, 70, number_tran_to_display_wan(c), 0x5656);  //屏幕右下
		draw_number(30+20+20+20+25+40, 70, number_tran_to_display_qian(c), 0x5656);
		draw_number(30+20+20+20+25+40+20, 70, number_tran_to_display_bai(c), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 70, number_tran_to_display_shi(c), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 70, number_tran_to_display_ge(c), 0x5656);*/
		
		draw_number(30+5+40, 260, number_tran_to_display_four(a), 0x5656);
		draw_number(30+5+40+20, 260, number_tran_to_display_three(a), 0x5656);  //屏幕右上
		draw_number(30+5+40+20+20, 260, number_tran_to_display_two(a), 0x5656);
		draw_number(30+5+40+20+20+20, 260, number_tran_to_display_one(a), 0x5656);
		/*draw_number(30+5+40+20+20+20+20, 260, number_tran_to_display_four(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 260, number_tran_to_display_three(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 260, number_tran_to_display_two(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 260, number_tran_to_display_one(a), 0x5656);*/
		
		draw_number(30+5+40, 140, number_tran_to_display_four(b), 0x5656);  //屏幕中
		draw_number(30+5+40+20, 140, number_tran_to_display_three(b), 0x5656);
		draw_number(30+5+40+20+20, 140, number_tran_to_display_two(b), 0x5656);
		draw_number(30+5+40+20+20+20, 140, number_tran_to_display_one(b), 0x5656);
	/*	draw_number(30+5+40+20+20+20+20, 140, number_tran_to_display_four(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 140, number_tran_to_display_three(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 140, number_tran_to_display_two(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 140, number_tran_to_display_one(b), 0x5656);*/
	
		draw_number(30+5+40, 40, number_tran_to_display_four(c), 0x5656);  //屏幕下
		draw_number(30+5+40+20, 40, number_tran_to_display_three(c), 0x5656);
		draw_number(30+5+40+20+20, 40, number_tran_to_display_two(c), 0x5656);
		draw_number(30+5+40+20+20+20, 40, number_tran_to_display_one(c), 0x5656);
	/*	draw_number(30+5+40+20+20+20+20, 40, number_tran_to_display_four(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 40, number_tran_to_display_three(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 40, number_tran_to_display_two(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 40, number_tran_to_display_one(c), 0x5656);*/
		
	//delay_ms(5);
	
	
}


void num_for_test(float x, float y, float z, int a, int b, int c)
{
	TFT_clear(0xffff);

		
		draw_number(10, 225, number_tran_to_display_wan(x), 0x5656); 
		draw_number(10+20, 225, number_tran_to_display_qian(x), 0x5656);  //屏幕左上
		draw_number(10+20+20, 225, number_tran_to_display_bai(x), 0x5656);
		draw_number(10+20+20+20, 225, number_tran_to_display_shi(x), 0x5656);
		draw_number(10+20+20+20+20, 225, number_tran_to_display_ge(x), 0x5656);
		
		draw_number(10, 145, number_tran_to_display_wan(y), 0x5656);  //屏幕中
		draw_number(10+20, 145, number_tran_to_display_qian(y), 0x5656);
		draw_number(10+20+20, 145, number_tran_to_display_bai(y), 0x5656);
		draw_number(10+20+20+20, 145, number_tran_to_display_shi(y), 0x5656);
		draw_number(10+20+20+20+20, 145, number_tran_to_display_ge(y), 0x5656);
	  
		draw_number(10, 70, number_tran_to_display_wan(z), 0x5656);  //屏幕下
		draw_number(10+20, 70, number_tran_to_display_qian(z), 0x5656);
		draw_number(10+20+20, 70, number_tran_to_display_bai(z), 0x5656);
		draw_number(10+20+20+20, 70, number_tran_to_display_shi(z), 0x5656);
		draw_number(10+20+20+20+20, 70, number_tran_to_display_ge(z), 0x5656);
		
		draw_number(30+20+20+25+40, 225, number_tran_to_display_wan(a), 0x5656);  //屏幕右上
		draw_number(30+20+20+20+25+40, 225, number_tran_to_display_qian(a), 0x5656);
		draw_number(30+20+20+20+25+40+20, 225, number_tran_to_display_bai(a), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 225, number_tran_to_display_shi(a), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 225, number_tran_to_display_ge(a), 0x5656);
		
		draw_number(30+20+20+25+40, 145, number_tran_to_display_wan(b), 0x5656);  //屏幕右中
		draw_number(30+20+20+20+25+40, 145, number_tran_to_display_qian(b), 0x5656);
		draw_number(30+20+20+20+25+40+20, 145, number_tran_to_display_bai(b), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 145, number_tran_to_display_shi(b), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 145, number_tran_to_display_ge(b), 0x5656);
		
		draw_number(30+20+20+25+40, 70, number_tran_to_display_wan(c), 0x5656); //屏幕右下
		draw_number(30+20+20+20+25+40, 70, number_tran_to_display_qian(c), 0x5656);
		draw_number(30+20+20+20+25+40+20, 70, number_tran_to_display_bai(c), 0x5656);
		draw_number(30+20+20+20+25+40+20+20, 70, number_tran_to_display_shi(c), 0x5656);
		draw_number(30+20+20+20+25+40+20+20+20, 70, number_tran_to_display_ge(c), 0x5656);
	delay_ms(500);
}

void num_for_dmp(float x, float y, float z,short int a,short int b,short int c, short int d)
{
	TFT_clear(0xffff);
		
		x *= 10;
		y *= 10;
		z *= 10;
	
		if(x <0){
		draw_number(10, 225, 'f', 0x5656); x=-x;}
		draw_number(10+20, 225, number_tran_to_display_qian(x), 0x5656);  //屏幕左上
		draw_number(10+20+20, 225, number_tran_to_display_bai(x), 0x5656);
		draw_number(10+20+20+20, 225, number_tran_to_display_shi(x), 0x5656);
		draw_point( 10+20+20+20+20, 200, 0x5656);
		draw_number(10+20+20+20+30, 225, number_tran_to_display_ge(x), 0x5656);
		if(y <0){
		draw_number(10, 145, 'f', 0x5656);y=-y;}  //屏幕中
		draw_number(10+20, 145, number_tran_to_display_qian(y), 0x5656);
		draw_number(10+20+20, 145, number_tran_to_display_bai(y), 0x5656);
		draw_number(10+20+20+20, 145, number_tran_to_display_shi(y), 0x5656);
		draw_point( 10+20+20+20+20, 120, 0x5656);
		draw_number(10+20+20+20+30, 145, number_tran_to_display_ge(y), 0x5656);
	  if(z <0){
		draw_number(10, 70, 'f', 0x5656);z=-z;}  //屏幕下}
		draw_number(10+20, 70, number_tran_to_display_qian(z), 0x5656);
		draw_number(10+20+20, 70, number_tran_to_display_bai(z), 0x5656);
		draw_number(10+20+20+20, 70, number_tran_to_display_shi(z), 0x5656);
		draw_point( 10+20+20+20+20, 45, 0x5656);
		draw_number(10+20+20+20+30, 70, number_tran_to_display_ge(z), 0x5656);

		
		if(a < 0){draw_number(30+5+40+40+20, 260, 'f', 0x5656); a=-a;}
		draw_number(30+5+40+40+40, 260, number_tran_to_display_four(a), 0x5656);
		draw_number(30+5+40+40+40+20, 260, number_tran_to_display_three(a), 0x5656);  //屏幕右上
		draw_number(30+5+40+40+40+20+20, 260, number_tran_to_display_two(a), 0x5656);
		draw_number(30+5+40+40+40+20+20+20, 260, number_tran_to_display_one(a), 0x5656);
		/*draw_number(30+5+40+20+20+20+20, 260, number_tran_to_display_four(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 260, number_tran_to_display_three(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 260, number_tran_to_display_two(a), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 260, number_tran_to_display_one(a), 0x5656);*/
		
		
		if(b < 0){draw_number(30+5+40+40+20, 190, 'f', 0x5656); b=-b;}
		draw_number(30+5+40+40+40, 190, number_tran_to_display_four(b), 0x5656);  //屏幕中
		draw_number(30+5+40+40+40+20, 190, number_tran_to_display_three(b), 0x5656);
		draw_number(30+5+40+40+40+20+20, 190, number_tran_to_display_two(b), 0x5656);
		draw_number(30+5+40+40+40+20+20+20, 190, number_tran_to_display_one(b), 0x5656);
	/*	draw_number(30+5+40+20+20+20+20, 140, number_tran_to_display_four(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 140, number_tran_to_display_three(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 140, number_tran_to_display_two(b), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 140, number_tran_to_display_one(b), 0x5656);*/
	
		
		if(c < 0){draw_number(30+5+40+40+20, 110, 'f', 0x5656); c=-c;}
		draw_number(30+5+40+40+40, 110, number_tran_to_display_four(c), 0x5656);  //屏幕下
		draw_number(30+5+40+40+40+20, 110, number_tran_to_display_three(c), 0x5656);
		draw_number(30+5+40+40+40+20+20, 110, number_tran_to_display_two(c), 0x5656);
		draw_number(30+5+40+40+40+20+20+20, 110, number_tran_to_display_one(c), 0x5656);
	/*	draw_number(30+5+40+20+20+20+20, 40, number_tran_to_display_four(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20, 40, number_tran_to_display_three(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20, 40, number_tran_to_display_two(c), 0x5656);
		draw_number(30+5+40+20+20+20+20+20+20+20, 40, number_tran_to_display_one(c), 0x5656);*/
		
		
		if(d < 0){draw_number(30+5+40+40+20, 40, 'f', 0x5656); c=-c;}
		draw_number(30+5+40+40+40, 40, number_tran_to_display_four(c), 0x5656);  //屏幕下
		draw_number(30+5+40+40+40+20, 40, number_tran_to_display_three(c), 0x5656);
		draw_number(30+5+40+40+40+20+20, 40, number_tran_to_display_two(c), 0x5656);
		draw_number(30+5+40+40+40+20+20+20, 40, number_tran_to_display_one(c), 0x5656);
	delay_ms(500);
}

void num_one_for_test(int a)
{
		delay_ms(500);
		TFT_clear(0xffff);
		draw_number(10, 225, number_tran_to_display_wan(a), 0x5656);
		draw_number(10+20, 225, number_tran_to_display_qian(a), 0x5656);  //屏幕左上
		draw_number(10+20+20, 225, number_tran_to_display_bai(a), 0x5656);
		draw_number(10+20+20+20, 225, number_tran_to_display_shi(a), 0x5656);
		draw_number(10+20+20+20+20, 225, number_tran_to_display_ge(a), 0x5656);
	
}






