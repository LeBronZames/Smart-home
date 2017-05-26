#include "Touch.h"
#include "LDC.h"


//216��֮��Ϊ������ִ�к����Լ��봥������ص�ִ�к���



u8 TP_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;//GPIO 
	 
		//ע��,ʱ��ʹ��֮��,��GPIO�Ĳ�������Ч
		//��������֮ǰ,����ʹ��ʱ��.����ʵ���������������

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC  | RCC_APB2Periph_AFIO, ENABLE);

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_0|GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOC, &GPIO_InitStructure);	

		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ; 
		GPIO_Init(GPIOC, &GPIO_InitStructure);  
	//	TP_Read_XY(&tp_dev.x[0],&tp_dev.y[0]);//��һ�ζ�ȡ��ʼ��	 
		
		
		
		
		//GPIOC->ODR|=0X200f;    //PC0~3 13 ȫ������
		/*
		if(TP_Get_Adjdata())return 0;//�Ѿ�У׼
		else			   //δУ׼?
		{ 										    
			LCD_Clear(WHITE);//����
			TP_Adjust();  //��ĻУ׼ 
			TP_Save_Adjdata();	 
		}			
		TP_Get_Adjdata();	
	}*/
	
	return 1; 									 
}




//Ĭ��Ϊtouchtype=0������.

 	 			    					   
//SPIд����
//������ICд��1byte����    
//num:Ҫд�������
void TP_Write_Byte(u8 num)    
{  
	u8 count=0;   
	for(count=0;count<8;count++)  
	{ 	  
		if(num&0x80)TDIN=1;  
		else TDIN=0;   
		num<<=1;    
		TCLK=0; 	 
		TCLK=1;		//��������Ч	        
	}		 			    
} 		 
//SPI������ 
//�Ӵ�����IC��ȡadcֵ
//CMD:ָ��
//����ֵ:����������	   
u16 TP_Read_AD(u8 CMD)	  
{ 	 
	u8 count=0; 	  
	u16 Num=0; 
	TCLK=0;		//������ʱ�� 	 
	TDIN=0; 	//����������
	TCS=0; 		//ѡ�д�����IC
	TP_Write_Byte(CMD);//����������
	delay_us(6);//ADS7846��ת��ʱ���Ϊ6us
	TCLK=0; 	     	    
	delay_us(1);    	   
	TCLK=1;		//��1��ʱ�ӣ����BUSY	    	    
	TCLK=0; 	     	    
	for(count=0;count<16;count++)//����16λ����,ֻ�и�12λ��Ч 
	{ 				  
		Num<<=1; 	 
		TCLK=0;	//�½�����Ч  	    	   
		TCLK=1;
		if(DOUT)Num++; 		 
	}  	
	Num>>=4;   	//ֻ�и�12λ��Ч.
	TCS=1;		//�ͷ�Ƭѡ	 
	return(Num);   
}




u16 ava_TP_Read_AD(u8 CMD)
{
	int a[5]; int i, j, temp,n,m;
	for(i = 0;i<5;i++)
	{
		a[i] = TP_Read_AD(CMD);
		delay_us(10);
	}
	
	n = 5;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
	
			m = (a[1]+a[2]+a[3])/3	;
	return m;
}


u16 get_TP_Read_AD(int coor)
{
	int xxx,xxx_2; 
	int x_p;
	xxx = 0; xxx_2 = 0;
	x_p = 0;
	if(coor == 0)
	{
	xxx = ava_TP_Read_AD(CMD_RDX);	
		 delay_us(100);
		 xxx_2 = ava_TP_Read_AD(CMD_RDX);
	}
	if(coor == 1)
	{
	xxx = ava_TP_Read_AD(CMD_RDY);	
		 delay_us(100);
		 xxx_2 = ava_TP_Read_AD(CMD_RDY);
	}
	
		 if(xxx_2> xxx)
		 {
			 if((xxx_2 - xxx) > 50)
			 {
				 x_p = 0;
			 }
			 else x_p = xxx;
		 }
		 if(xxx_2< xxx)
		 {
			 if((xxx - xxx_2) > 50)
			 {
				 x_p = 0;
			 }
			 else x_p = xxx;
		 }
	xxx = 0;
		 xxx_2 = 0;
	
	return x_p;
}


int read_x_LCD(void)
{
	int a;
	a = (250-get_TP_Read_AD(0)/15);
	return a;
}

int read_y_LCD(void)
{
	int b;
	b = (get_TP_Read_AD(1)/11.8 )-20;
	return b;
}
//void draw_P_lcd(void)
//{
//	int a,b;
//		 a = read_x_LCD(); delay_us(100);b = read_y_LCD();
//		 if(a > 5 && b > 5 && a < 245 && b < 330)
//		 {
//				draw_point(a, b, 0x5656);
//		 }
//		 a = 0; b = 0;
//}
 

void draw_P_lcd(void)
{
	int a,b;
		 a = 245-read_x_LCD(); delay_us(100);b = read_y_LCD();
		 if(a > 5 && b > 5 && a < 245 && b < 330)
		 {
				draw_point_four(a, b, 0x5656);
		 }
		 a = 0; b = 0;
}


int check_P_lcd(int *a, int *b)
{

		 *a = 245-read_x_LCD(); delay_us(100);*b = read_y_LCD();
		 if(*a > 5 && *b > 5 && *a < 245 && *b < 330)
		 {
				return 1;
		 }
		 else return 0;
}


//******************************************************************************//

int check_touch(void){
	int flag = 0;
	int a=0,b=0;
	flag = check_P_lcd(&a, &b);
	if(flag == 1){
		if((a>=10)&(a<=90)&(b>=10)&(b<=70)){  //0,0
			flag = 0;
			a = 0;b = 0;
			return 1;
		}
		if((a>=91)&(a<=179)&(b>=10)&(b<=70)){  //0,1
			flag = 0;
			a = 0;b = 0;
			return 2;
		}
		if((a>=180)&(a<=250)&(b>=10)&(b<=70)){  //0,2
			flag = 0;
			a = 0;b = 0;
			return 3;
		}
		///////
		if((a>=10)&(a<=90)&(b>=85)&(b<=140)){  //1,0
			flag = 0;
			a = 0;b = 0;
			return 4;
		}
		if((a>=91)&(a<=179)&(b>=85)&(b<=140)){  //1,1
			flag = 0;
			a = 0;b = 0;
			return 5;
		}
		if((a>=180)&(a<=250)&(b>=85)&(b<=140)){  //1,2
			flag = 0;
			a = 0;b = 0;
			return 6;
		}
		//////
		///////
		if((a>=10)&(a<=90)&(b>=170)&(b<=230)){  //2,0
			flag = 0;
			a = 0;b = 0;
			return 7;
		}
		if((a>=91)&(a<=179)&(b>=170)&(b<=230)){  //2,1
			flag = 0;
			a = 0;b = 0;
			return 8;
		}
		if((a>=180)&(a<=250)&(b>=170)&(b<=230)){  //2,2
			flag = 0;
			a = 0;b = 0;
			return 9;
		}
		//*********************************************//
		if((a>=10)&(a<=90)&(b>=230)){  //3,0
			flag = 0;
			a = 0;b = 0;
			return 10;
		}
		if((a>=91)&(a<=179)&(b>=230)){  //3,1
			flag = 0;
			a = 0;b = 0;
			return 11;
		}
		if((a>=180)&(a<=250)&(b>=230)){  //3,2
			flag = 0;
			a = 0;b = 0;
			return 12;
		}
		
		
	}
	
	
	 return 0;

	
}

















