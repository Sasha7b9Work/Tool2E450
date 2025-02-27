//===========================================================

//write one byte to SD
sbit SD_CLK = P1^7;
sbit SD_DI  = P1^5;
sbit SD_DO  = P1^6;
sbit SD_CS  = P1^4;

//Buffer
unsigned char xdata DATA[512]=0;

//===========================================================
//write one byte to SD
void SdWrite(unsigned char n)
{

unsigned char i;

for(i=8;i;i--)
{
SD_CLK=0;
SD_DI=(n&0x80);
n<<=1;
SD_CLK=1;
}
SD_DI=1; 
} 
//===========================================================
//read one byte
unsigned char SdRead()
{
unsigned char n,i;
for(i=8;i;i--)
{
SD_CLK=0;
SD_CLK=1;
n<<=1;
if(SD_DO) n|=1;

}
return n;
}
//============================================================
//Detecting the response of the SD card
unsigned char SdResponse()
{
unsigned char i=0,response;

while(i<=8)
{
response = SdRead();
if(response==0x00)
break;
if(response==0x01)
break;
i++;
}
return response;
} 
//================================================================
//Send commands to the SD card
void SdCommand(unsigned char command, unsigned long argument, unsigned char CRC)
{

SdWrite(command|0x40);
SdWrite(((unsigned char *)&argument)[0]);
SdWrite(((unsigned char *)&argument)[1]);
SdWrite(((unsigned char *)&argument)[2]);
SdWrite(((unsigned char *)&argument)[3]);
SdWrite(CRC);
}
//================================================================
//Initialize the SD card
unsigned char SdInit(void)
{
int delay=0, trials=0;
unsigned char i;
unsigned char response=0x01;

SD_CS=1;
for(i=0;i<=9;i++)
SdWrite(0xff);
SD_CS=0;

//Send Command 0 to put MMC in SPI mode
SdCommand(0x00,0,0x95);


response=SdResponse();

if(response!=0x01)
{
return 0;
} 

while(response==0x01)
{
SD_CS=1;
SdWrite(0xff);
SD_CS=0;
SdCommand(0x01,0x00ffc000,0xff);
response=SdResponse();
} 

SD_CS=1;
SdWrite(0xff);
return 1; 
}
//================================================================
//Specify the address to write  the SD card data, a maximum of 512 bytes
unsigned char SdWriteBlock(unsigned char *Block, unsigned long address,int len)
{
unsigned int count;
unsigned char dataResp;
//Block size is 512 bytes exactly
//First Lower SS

SD_CS=0;
//Then send write command
SdCommand(0x18,address,0xff);

if(SdResponse()==00)
{
SdWrite(0xff);
SdWrite(0xff);
SdWrite(0xff);
//command was a success - now send data
//start with DATA TOKEN = 0xFE
SdWrite(0xfe);
//now send data
for(count=0;count<len;count++) SdWrite(*Block++);

for(;count<512;count++) SdWrite(0);
//data block sent - now send checksum
SdWrite(0xff);
SdWrite(0xff);
//Now read in the DATA RESPONSE token
dataResp=SdRead();
//Following the DATA RESPONSE token
//are a number of BUSY bytes
//a zero byte indicates the MMC is busy

while(SdRead()==0);

dataResp=dataResp&0x0f; //mask the high byte of the DATA RESPONSE token
SD_CS=1;
SdWrite(0xff);
if(dataResp==0x0b)
{
//printf("DATA WAS NOT ACCEPTED BY CARD -- CRC ERROR\n");
return 0;
}
if(dataResp==0x05)
return 1;

//printf("Invalid data Response token.\n");
return 0;
}
//printf("Command 0x18 (Write) was not received by the MMC.\n");
return 0;
}

//=======================================================================
//Specified address from the SD card to read data, a maximum of 512 bytes
unsigned char SdReadBlock(unsigned char *Block, unsigned long address,int len)
{
unsigned int count;
//Block size is 512 bytes exactly
//First Lower SS

 //printf("MMC_read_block\n");

SD_CS=0;
//Then send write command
SdCommand(0x11,address,0xff);

if(SdResponse()==00)
{
//command was a success - now send data
//start with DATA TOKEN = 0xFE
while(SdRead()!=0xfe);

for(count=0;count<len;count++) *Block++=SdRead(); 

for(;count<512;count++) SdRead();

//data block sent - now send checksum
SdRead();
SdRead();
//Now read in the DATA RESPONSE token
SD_CS=1;
SdRead();
return 1;
}
 //printf("Command 0x11 (Read) was not received by the MMC.\n");
return 0;
}


void Display_JPG_SDCARD()///SD card physical address of the first data address initial value
{ unsigned long jn;  
  unsigned int in;
 // unsigned long AddTemp=314880;///SD card physical address of the first data address initial value  1G CARD
  unsigned long AddTemp=317952;///SD card physical address of the first data address initial value    256M CARD
  unsigned char mn=16;  //Total number of picture


    Select_Main_Window_16bpp();
	Main_Image_Start_Address(0);				
	Main_Image_Width(1024);							
	Main_Window_Start_XY(0,0);

	Canvas_Image_Start_address(0);//Layer 1
	Canvas_image_width(1024);//
    Active_Window_XY(0,0);
	Active_Window_WH(1024,600);

	Foreground_color_65k(Blue);
	Line_Start_XY(0,0);
	Line_End_XY(1023,599);
	Start_Square_Fill();
  
  	
 		SdInit();        
	for(;mn!=0;mn--) 
	 {	
      	LCD_SetCursor(0,0);
     //	LCD_CmdWrite(0x04); //
	 	
	 	for(jn=0;jn<2400;jn++)      //A picture information  comprising 2400x512 bytes
		    {
		    SdReadBlock(DATA,AddTemp+(jn*512),512);  
		   	LCD_WriteRAM_Prepare();
		    for(in=0;in<512;in+=2)                   
			   {   
			    LCD_DataWrite(DATA[in+1]);	
			    LCD_DataWrite(DATA[in]);				 
		       }
			   while(!next)return;
		     } 
		     AddTemp = AddTemp+((jn+0)*512);         
			 
		 	NextStep(); 
	}
                       


} 