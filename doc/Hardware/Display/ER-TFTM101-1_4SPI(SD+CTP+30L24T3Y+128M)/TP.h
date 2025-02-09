

/* touch panel interface define */
sbit SDA1	   =    P3^0;
sbit SCL1       =    P3^1;
sbit PEN_INT       =    P3^2;	
sbit RESET	   =	P3^3;

sbit LED	   =	P3^7;

//Touch Status	 
#define Key_Down 0x01
#define Key_Up   0x00 


struct _ts_event
{
    uint    x1;
    uint    y1;
    uint    x2;
    uint    y2;
    uint    x3;
    uint    y3;
    uint    x4;
    uint    y4;
    uint    x5;
    uint    y5;
    uint    x6;
    uint    y6;
    uint    x7;
    uint    y7;
    uint    x8;
    uint    y8;
    uint    x9;
    uint    y9;
    uint    x10;
    uint    y10;	
    uchar     touch_point;
	uchar     Key_Sta;	
};

struct _ts_event ts_event; 

#define WRITE_ADD	0xba 
#define READ_ADD	0xbb

#define CT_MAX_TOUCH    10		//电容触摸屏最大支持的点数

// Registers define
#define GTP_READ_COOR_ADDR    0x814e
#define GTP_REG_SLEEP         0x8040
#define GTP_REG_SENSOR_ID     0x814a
#define GTP_REG_CONFIG_DATA   0x8047
#define GTP_REG_VERSION       0x8440

//#define CT_READ_XY_REG 	0x814E  	//读取坐标寄存器 
//#define CT_CONFIG_REG   0x8047	//配置参数起始寄存器

 uchar code GTP_CFG_DATA[]=
{

0x63,0x00,0x04,0x58,0x02,0x0A,0x3D,0x00,
0x01,0x08,0x28,0x0F,0x50,0x32,0x03,0x05,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x17,
0x19,0x1D,0x14,0x90,0x2F,0x89,0x23,0x25,
0xD3,0x07,0x00,0x00,0x00,0x02,0x03,0x1D,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x19,0x32,0x94,0xD5,0x02,
0x07,0x00,0x00,0x04,0xA2,0x1A,0x00,0x90,
0x1E,0x00,0x80,0x23,0x00,0x73,0x28,0x00,
0x68,0x2E,0x00,0x68,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x16,0x15,0x14,0x11,0x10,0x0F,0x0E,0x0D,
0x0C,0x09,0x08,0x07,0x06,0x05,0x04,0x01,
0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x29,0x28,
0x27,0x26,0x25,0x24,0x23,0x22,0x21,0x20,
0x1F,0x1E,0x1C,0x1B,0x19,0x14,0x13,0x12,
0x11,0x10,0x0F,0x0E,0x0D,0x0C,0x0A,0x08,
0x07,0x06,0x04,0x02,0x00,0xFF,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x71,0x01


};


void TOUCH_Init(void);
void TOUCH_Start(void);
void TOUCH_Stop(void);
uchar   TOUCH_Wait_Ack(void);
void TOUCH_Ack(void);
void TOUCH_NAck(void);

void TOUCH_Send_Byte(uchar txd);
uchar TOUCH_Read_Byte(unsigned char ack);
void Draw_Big_Point(uint x,uint y,uint colour);
uchar gt9271_read_data(void);
void inttostr(uint value,uchar *str);


//IIC start
void TOUCH_Start(void)
{ 
	SDA1=1;  
	_nop_();
	SCL1=1;
	delay_us(3);
	SDA1=0;  
	delay_us(3);
	SCL1=0;
//	delay_us(1);
}	  


//IIC stop
void TOUCH_Stop(void)
{
	SDA1=0;
	_nop_();
	SCL1=1;
	delay_us(3);
	SDA1=1;
	delay_us(3);
	SCL1=0;
//	delay_us(1);						   	
}


//Wait for an answer signal
uchar TOUCH_Wait_Ack(void)
{	uchar errtime=0;

	SDA1=1;
//	delay_us(1);
	SCL1=1;
//	delay_us(1);
  	while(SDA1)
	{
	  /*  errtime++;
	    if(errtime>250)
		    {
		      TOUCH_Stop();
		      return 1;
		    }	*/
	   ;
	}
	SCL1=0;
//	delay_us(1);
	return 0;
}



//Acknowledge
void TOUCH_Ack(void)
{	SCL1=0;
	_nop_();
	SDA1=0;
	delay_us(2);
	SCL1=1;
	delay_us(2);
	SCL1=0;
	_nop_();
}



//NO Acknowledge		    
void TOUCH_NAck(void)
{	SCL1=0;
	delay_us(1);
	SDA1=1;
	delay_us(2);
	SCL1=1;
	delay_us(2);
	SCL1=0;
	_nop_();
}	
	

//IIC send one byte		  
void TOUCH_Send_Byte(uchar Byte)
{	uchar t;  		
 	SCL1=0; 
//	delayus(5);
    for(t=0;t<8;t++)
    {           
	   	SDA1=(bit)(Byte & 0x80) ;
	   	Byte <<=1;
		delay_us(2);
	   	SCL1=1;
		delay_us(2);
	   	SCL1=0;
	//	delayus(5);
    }	

} 

//Read one byte，ack=0，Send Acknowledge，ack=1，NO Acknowledge   
uchar TOUCH_Read_Byte(uchar ack)
{	uchar t,receive=0;

	SCL1=0;
//	delayus(5);
	SDA1=1;
//	delayus(5);
	for(t = 0; t < 8; t++)
	{	_nop_();
	 	SCL1 = 0;
		delay_us(4);
	 	SCL1=1;
		delay_us(4);
	 	receive<<=1;
	 	if(SDA1)receive=receive|0x01;
	//	delayus(5);
	}

					 
   	if (ack)  TOUCH_NAck();//NO Acknowledge 
   	else       TOUCH_Ack(); //Send Acknowledge   
    
	 return receive;
}

uchar gt9271_WR_Reg(uint reg,uchar *buf,uchar len)
{
	uchar i;
	uchar ret=0;
	TOUCH_Start();	
 	TOUCH_Send_Byte(WRITE_ADD);   	//发送写命令 	 
	TOUCH_Wait_Ack();
	TOUCH_Send_Byte(reg>>8);   	//发送高8位地址
	TOUCH_Wait_Ack();	 										  		   
	TOUCH_Send_Byte(reg&0XFF);   	//发送低8位地址
	TOUCH_Wait_Ack(); 
	for(i=0;i<len;i++)
	{	   
    	TOUCH_Send_Byte(buf[i]);  	//发数据
		ret=TOUCH_Wait_Ack();
		if(ret)break;  
	}
    TOUCH_Stop();					//产生一个停止条件	    
	return ret; 
}


void gt9271_RD_Reg(uint reg,uchar *buf,uchar len)
{
	uchar i;
 	TOUCH_Start();	
 	TOUCH_Send_Byte(WRITE_ADD);   	//发送写命令 	 
	TOUCH_Wait_Ack(); 
 	TOUCH_Send_Byte(reg>>8);   	//发送高8位地址
	TOUCH_Wait_Ack();  										  		   
 	TOUCH_Send_Byte(reg&0XFF);   	//发送低8位地址
	TOUCH_Wait_Ack();
  
 	TOUCH_Start(); 	 	   
	TOUCH_Send_Byte(READ_ADD);    //发送读命令		   
	TOUCH_Wait_Ack();    
	for(i=0;i<len;i++)
	{	   
    	buf[i]=TOUCH_Read_Byte(i==(len-1)?1:0); //发数据
		
		
	//	if(i==(len-1))  buf[i]=TOUCH_Read_Byte(1);
	//	else            buf[i]=TOUCH_Read_Byte(0);	 
		
	} 
     TOUCH_Stop();//产生一个停止条件	    
}

uchar gt9271_Send_Cfg(uchar * buf,uint cfg_len)
{
	uchar ret=0;
	uchar retry=0;
	for(retry=0;retry<5;retry++)
	{
		ret=gt9271_WR_Reg(GTP_REG_CONFIG_DATA,buf,cfg_len);
		if(ret==0)break;
		delay_ms(10);	 
	}
	return ret;
}

/******************************************************************************************
*Function name：Draw_Big_Point(u16 x,u16 y)
* Parameter：uint16_t x,uint16_t y xy
* Return Value：void
* Function：Draw touch pen nib point 3 * 3
*********************************************************************************************/		   
void Draw_Big_Point(uint x,uint y,uint colour)
{    Graphic_Mode();
	 Goto_Pixel_XY(x-1,y-1); 
	 LCD_CmdWrite(0x04);  
	LCD_DataWrite(colour);
	LCD_DataWrite(colour);
	LCD_DataWrite(colour);
	Goto_Pixel_XY(x-1,y);//Memory write position
	LCD_CmdWrite(0x04); 					   
	LCD_DataWrite(colour);
	LCD_DataWrite(colour);
 	LCD_DataWrite(colour);
 	Goto_Pixel_XY(x-1,y+1);//Memory write position
	LCD_CmdWrite(0x04); 					   
	LCD_DataWrite(colour);
	LCD_DataWrite(colour);
 	LCD_DataWrite(colour);
}

uchar gt9271_read_data(void)
{	uchar buf[80] = {0xff}; uchar ret = 0;	uchar ss[4];


	gt9271_RD_Reg(GTP_READ_COOR_ADDR,buf,80);		//一次读取80个字节

	ss[0]=0;		
 	gt9271_WR_Reg(GTP_READ_COOR_ADDR,ss,1);	  //Must clear  Buffer status
 
  	ts_event.touch_point = buf[0] & 0x0f;


 

  	if (ts_event.touch_point == 0) 
		{  			

			return 0;
  		}		
   

					switch (ts_event.touch_point) 
					{
 							case 10:
				           			ts_event.x10 = (uint)(buf[75] )<<8 | (uint)buf[74];
				           			ts_event.y10 = (uint)(buf[77] )<<8 | (uint)buf[76];

  							case 9:
				           			ts_event.x9 = (uint)(buf[67] )<<8 | (uint)buf[66];
				           			ts_event.y9 = (uint)(buf[69] )<<8 | (uint)buf[68];

  							case 8:
				           			ts_event.x8 = (uint)(buf[59] )<<8 | (uint)buf[58];
				           			ts_event.y8 = (uint)(buf[61] )<<8 | (uint)buf[60];

  							case 7:
				           			ts_event.x7 = (uint)(buf[51] )<<8 | (uint)buf[50];
				           			ts_event.y7 = (uint)(buf[53] )<<8 | (uint)buf[52];

							case 6:
				           			ts_event.x6 = (uint)(buf[43] )<<8 | (uint)buf[42];
				           			ts_event.y6 = (uint)(buf[45] )<<8 | (uint)buf[44];	 

							case 5:
				           			ts_event.x5 = (uint)(buf[35] )<<8 | (uint)buf[34];
				           			ts_event.y5 = (uint)(buf[37] )<<8 | (uint)buf[36];
				
						    case 4:
						           	ts_event.x4 = (uint)(buf[27] )<<8 | (uint)buf[26];
						           	ts_event.y4 = (uint)(buf[29] )<<8 | (uint)buf[28];
						
						    case 3:
						           	ts_event.x3 = (uint)(buf[19] )<<8 | (uint)buf[18];
						           	ts_event.y3 = (uint)(buf[21] )<<8 | (uint)buf[20];
						
						    case 2:
						           	ts_event.x2 = (uint)(buf[11] )<<8 | (uint)buf[10];
						           	ts_event.y2 = (uint)(buf[13] )<<8 | (uint)buf[12];
						
						    case 1:
						           	ts_event.x1 = (uint)(buf[3] )<<8 | (uint)buf[2];
						           	ts_event.y1 = (uint)(buf[5] )<<8 | (uint)buf[4];
				
				    break;
						    default:
						    return 0;
					}


	   
	return ret;
}


void inttostr(uint value,uchar *str)
{
	str[0]=value/1000+48;
	str[1]=value%1000/100+48;
	str[2]=value%1000%100/10+48;
 	str[3]=value%1000%100%10+48;
}



void TOUCH_Init(void)
{	
	/*	RESET=0;
		PEN_INT=0;
		Delay1ms(30);
 		PEN_INT=1;
		Delay1ms(5);
		RESET=1;;
		Delay1ms(20);
		ACC=PEN_INT;
		ACC=PEN_INT;
 		Delay1ms(200);	 */

 		RESET=0;						   
		PEN_INT=0;
		delay_ms(20);
 		RESET=1;
		delay_ms(500);
		ACC=PEN_INT;
 		ACC=PEN_INT;
 		delay_ms(200);

		ts_event.x1=0;
		ts_event.y1=0;
		ts_event.x2=0;
		ts_event.y2=0;
		ts_event.x3=0;
		ts_event.y3=0;
		ts_event.x4=0;
		ts_event.y4=0;
		ts_event.x5=0;
		ts_event.y5=0;
		ts_event.x6=0;
		ts_event.y6=0;
		ts_event.x7=0;
		ts_event.y7=0;
		ts_event.x8=0;
		ts_event.y8=0;
		ts_event.x9=0;
		ts_event.y9=0;
		ts_event.x10=0;
		ts_event.y10=0;
	   
}						  


void TPTEST(void)
{uchar ss[4];uchar bb[187]; uchar re=1;	uchar i;  
   	ts_event.Key_Sta=Key_Up;
	  

		Select_Main_Window_16bpp();
		Main_Image_Start_Address(0);				
		Main_Image_Width(1024);							
		Main_Window_Start_XY(0,0);	

    	Canvas_Image_Start_address(0);//Layer 1
		Canvas_image_width(1024);//
    	Active_Window_XY(0,0);
		Active_Window_WH(1024,600);

		Foreground_color_65k(Black);
		Line_Start_XY(0,0);
		Line_End_XY(1023,599);
		Start_Square_Fill();

		 Foreground_color_65k(Black);
	Background_color_65k(Blue2);
	CGROM_Select_Internal_CGROM();
	Font_Select_12x24_24x24();
 	Goto_Text_XY(0,Line1);
	Show_String("www.buydisplay.ocm  Capacitive touch screen test");





  	Foreground_color_65k(White);
	Background_color_65k(Black);
	CGROM_Select_Internal_CGROM();
	Font_Select_8x16_16x16();
	

				TOUCH_Init();

			re=gt9271_Send_Cfg((uchar*)GTP_CFG_DATA,sizeof(GTP_CFG_DATA));
			if(re==0)
			{Goto_Text_XY(0,60);Show_String("send CFG OK");}
	 		else  {Goto_Text_XY(0,60);Show_String("send CFG NOK");}
		  
		  
 /*	   
	 	gt9271_RD_Reg(GTP_REG_CONFIG_DATA,bb,sizeof(GTP_CFG_DATA));

		  
		i=0;
		  Text_Mode();
		 Goto_Text_XY(0,100);
	 while(i<186)				
		{	inttostr(bb[i],ss);
		 LCD_CmdWrite(0x04);
		LCD_DataWrite(ss[0]);	delay_us(2); Check_Mem_WR_FIFO_not_Full();	
		LCD_DataWrite(ss[1]);	delay_us(2); Check_Mem_WR_FIFO_not_Full();
		LCD_DataWrite(ss[2]);	delay_us(2);  Check_Mem_WR_FIFO_not_Full();
		LCD_DataWrite(ss[3]);	delay_us(2);  Check_Mem_WR_FIFO_not_Full();
		LCD_DataWrite(',');	delay_us(2);   Check_Mem_WR_FIFO_not_Full();
		i+=1;
		}
*/		   




	while(next)
	{
		  	Goto_Text_XY(0,465);
		  	Show_String("Touch to display the coordinate");



	   gt9271_RD_Reg(GTP_READ_COOR_ADDR,ss,1);
	   if(ss[0]&0x80)
			{

										   

					gt9271_read_data();
					ts_event.Key_Sta=Key_Up;
		


					inttostr(ts_event.x1,ss);	
			
					 
				  	Goto_Text_XY(250,465);   //Set the display position
				  	
				  	Show_String("X=");
					Text_Mode();   
					LCD_CmdWrite(0x04);
				  	LCD_DataWrite(ss[0]);
					 Check_Mem_WR_FIFO_not_Full();
				  	LCD_DataWrite(ss[1]);
					 Check_Mem_WR_FIFO_not_Full();
				  	LCD_DataWrite(ss[2]);
					 Check_Mem_WR_FIFO_not_Full();
 				  	LCD_DataWrite(ss[3]);
					 Check_Mem_WR_FIFO_not_Full();

					inttostr(ts_event.y1,ss);
				  	Goto_Text_XY(350, 465);   //Set the display position
				  	
				  	Show_String("Y=");
 					Text_Mode();		 
					LCD_CmdWrite(0x04);
				  	LCD_DataWrite(ss[0]);
					 Check_Mem_WR_FIFO_not_Full();
				  	LCD_DataWrite(ss[1]);
					 Check_Mem_WR_FIFO_not_Full();
				  	LCD_DataWrite(ss[2]);
					 Check_Mem_WR_FIFO_not_Full();
				  	LCD_DataWrite(ss[3]);
					  Check_Mem_WR_FIFO_not_Full();

					Draw_Big_Point(1024-ts_event.x1,600-ts_event.y1,color65k_red);
					Draw_Big_Point(1024-ts_event.x2,600-ts_event.y2,color65k_green);	
					Draw_Big_Point(1024-ts_event.x3,600-ts_event.y3,color65k_blue);
					Draw_Big_Point(1024-ts_event.x4,600-ts_event.y4,color65k_cyan);	
					Draw_Big_Point(1024-ts_event.x5,600-ts_event.y5,color65k_purple);
 					Draw_Big_Point(1024-ts_event.x6,600-ts_event.y6,color65k_white);
					Draw_Big_Point(1024-ts_event.x7,600-ts_event.y7,color65k_yellow);
					Draw_Big_Point(1024-ts_event.x8,600-ts_event.y8,0xc00c);
					Draw_Big_Point(1024-ts_event.x9,600-ts_event.y9,0xc0c0);
					Draw_Big_Point(1024-ts_event.x10,600-ts_event.y10,0x0307);

                   
			}


    }



}












