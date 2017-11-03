#include "82GXX.H"

void test_led(void);
void delay_1ms(int count);
void disp_7_seg(int m,int n,int o,int p,char Point,int delay);

char code Scan[4]={0x7F,0xBF,0xDF,0xEF};
char code Data[11]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x90,0xFF};

char code Point_ON=0x7F,Point_OFF=0xFF;

main()
{
	int i;
	test_led();
	while(1)
	{
		for(i=0;i<7;i++) disp_7_seg(i,i+1,i+2,i+3,Point_ON,500);
		for(i=5;i>0;i--) disp_7_seg(i,i+1,i+2,i+3,Point_OFF,500);
	}
}

void disp_7_seg(int m,int n,int o,int p,char Point,int delay)
{
	int x , i, j;
	int r[4];
	r[0] = m;
	r[1] = n;
	r[2] = o;
	r[3] = p;
	for(i=0;i<(delay/10);i++)
	{
		for(x=0;x<4;x++)
		{
			P0=Data[r[x]]&Point;
			P2=Scan[x];
			delay_1ms(10);
		}
	}
}

void test_led(void)
{
	int i;
	for(i=0;i<3;i++) 
	{
		disp_7_seg(8,8,8,8,Point_ON,500);
		disp_7_seg(10,10,10,10,Point_OFF,500);
	}
}

void delay_1ms(int count)
{
	int i,j;
	for(i=0;i<count;i++) for(j=0;j<400;j++);
}