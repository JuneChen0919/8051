#include "82GXX.H"

sbit P2_A = P2^0;
sbit P2_B = P2^1;
sbit P2_C = P2^2;
sbit P2_D = P2^3;

char code Scan[4]={0x7F,0xBF,0xDF,0xEF};
char code Data[11]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x90,0xFF};
char code Point_ON=0x7F,Point_OFF=0xFF;

void delay_1ms(int count);

main()
{
	int i;
	while(1)
	{
		for(i=0;i<4;i++)
		{
			P2=Scan[i];
			
			delay_1ms(1);
		}
	}
	
}


void delay_1ms(int count)
{
	int i,j;
	for(i=0;i<count;i++) for(j=0;j<463;j++);
}