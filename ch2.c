#include "82GXX.H"

sbit start_pb = P3^2 ;
sbit stop_pb = P3^3 ;
sbit reset_pb = P3^4 ;

void test_led(void);
int start(int);
int stop(int);
void delay_1ms(int count);

int i, j, s;

unsigned char code data_7seg[16]=
{ 0xC0,0xF9,0xA4,0xB0,
0x99,0x92,0x82,0xD8,
0x80,0x90,0x88,0x00,
0xC6,0x40,0x86,0x8E };

main()
{
	test_led();
	P0=0xC0;
	P2=0xC0;
	while(1)
	{
		if(start_pb==0)
		{
			start(0);
		}
	}
}

int start(int x)
{
	int m=x/10, n=x%10;
	while(stop_pb==1)
	{
		for(i=m;i<10;i++)
		{
			P2=data_7seg[i];
			if(stop_pb==0)
			{
				stop(s);
			}
			else if(reset_pb==0)
			{
				s = 0;
				x = 0;
				//y = 0;
				//k = 0;
				i = 0;
				j = 0;
				m = 0;
				n = 0;
				P0=0xC0;
				P2=0xC0;
				delay_1ms(1000);
			}
			for(j=n;j<10;j++)
			{
				P0=data_7seg[j];
				s ++;
				m=0;
				n=0;
				delay_1ms(1000);
				if(stop_pb==0)
				{
					stop(s);
				}
				else if(reset_pb==0)
				{
					s = 0;
					x = 0;
					//y = 0;
					//k = 0;
					i = 0;
					j = 0;
					m = 0;
					n = 0;
					P0=0xC0;
					P2=0xC0;
					delay_1ms(1000);
				}
			}
		}
		s = 0;
		x = 0;
	}
	
}

int stop(int y)
{
	int k;
	k = y;
	P2=data_7seg[y/10];
	P0=data_7seg[y%10];
	delay_1ms(100);
	while(1)
	{
		if(start_pb==0)
		{
			start(k);
		}
		if(reset_pb==0)
		{
			P0=0xC0;
			P2=0xC0;
			y = 0;
			k = 0;
			i = 0;
			j = 0;
			s = 0;
			if(start_pb==0)
			{
				start(0);
			}
		}
	}
}

void test_led(void)
{ int i;
	for(i=0;i<3;i++)
	{
	P0=0x00;
	P2=0x00;
	delay_1ms(1000);
	P0=0xFF;
	P2=0xFF;
	delay_1ms(1000);
	}
}

void delay_1ms(int count)
{ int i,j;
for(i=0;i<count;i++) for(j=0;j<250;j++);
}

