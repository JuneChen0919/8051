#include "82GXX.H"
#define COUNT 90


sbit start_pb = P3^2 ;
sbit stop_pb = P3^3 ;
sbit reset_pb = P3^4 ;

void test_led(void);
void delay_1ms(int count);
int disp_7_seg(int m,int n,int o,int p,char Point,int delay);
int stop(int y);
int start(int x);

char code Scan[4]={0x7F,0xBF,0xDF,0xEF};
char code Data[11]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x90,0xFF};

char code Point_ON=0x7F,Point_OFF=0xFF;

int test = 1;

main()
{
	test_led();
	while(1)
	{
		disp_7_seg(0,0,0,0,Point_OFF,10);
		if(start_pb==0)
		{
			//test_led();
			start(0);
		}
	}
}

int start(int x)
{
	int m, n, o, p;
	while(1)
	{
		m=x/1000;
		n=(x%1000)/100;
		o=(x%100)/10;
		p=x%10;
		disp_7_seg(m,n,o,p,Point_OFF,COUNT);
		x ++;
		if(stop_pb == 0)
		{
			x = stop(x);
		}
		if(reset_pb == 0)
		{
			x = 0;
		}
		if(x>=10000) x = 0;
	}
	
}

int stop(int y)
{
	int m, n, o, p;
	m=y/1000;
	n=(y%1000)/100;
	o=(y%100)/10;
	p=y%10;
	while(1)
	{
		disp_7_seg(m,n,o,p,Point_OFF,10);
		if(start_pb==0)
		{
			return y;
		}
		if(reset_pb==0)
		{
			y = 0;
			while(1)
			{
				disp_7_seg(0,0,0,0,Point_OFF,10);
				if(start_pb==0)
				{
					return 0;
				}
			}
		}
	}
	
}

int disp_7_seg(int m,int n,int o,int p,char Point,int delay)
{
	int x , i;//, j;
	int r[4];
	r[0] = m;
	r[1] = n;
	r[2] = o;
	r[3] = p;
	for(i=0;i<(delay/10);i++)
	{
		for(x=0;x<4;x++)
		{
			if(test == 0)
			{
				if(x == 1)
				{
					Point = Point_ON;
				}
				else
				{
					Point = Point_OFF;
				}
			}
			P0=Data[r[x]]&Point;
			P2=Scan[x];
			
			delay_1ms(1);
		}
		if(reset_pb == 0)
		{
			m = 0;
			n = 0;
			o = 0;
			p = 0;
			break;
		}
		if(stop_pb == 0) return 0;
	}
	return 0;
}

void test_led(void)
{
	int i;
	for(i=0;i<3;i++) 
	{
		disp_7_seg(8,8,8,8,Point_ON,3000);
		disp_7_seg(10,10,10,10,Point_OFF,3000);
	}
	test = 0;
}

void delay_1ms(int count)
{
	int i,j;
	for(i=0;i<count;i++) for(j=0;j<463;j++);
}