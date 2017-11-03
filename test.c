#include <reg51.h>

sbit l_pb = P0^0 ;
sbit r_pb = P0^1 ;
sbit s_pb = P0^2 ;

void delay(int count);

void r_shift(int k)
{
	while(1)
	{
		P2 = k;
		delay(2000);
		k = k >> 1;
		P2 = k;
		k += 0x80;
		P2 = k;
		if(k >= 0xFF)
		{
			k = 0x7F;
			P2 = k;
		}
		
		if(l_pb==0) break;
		if(s_pb==0)
		{
			while(l_pb&&r_pb==1);
			break;
		}
	}
}

void l_shift(int k)
{
	while(1)
	{
		P2 = k;
		delay(2000);
		k = k << 1;
		P2 = k;
		k ++;
		P2 = k;
		k -= 0x100;//256 
		P2 = k;
		if(k <= 0)
		{
			k = 0xFE;
			P2 = k;
		}
		
		if(r_pb==0) break;
		if(s_pb==0)
		{
			while(l_pb&&r_pb==1);
			break;
		}
	}
}

void main()
{
	int x;
	while(l_pb&&r_pb==1)
	{
		x = 0xFF;
		P2 = x;
	}
	x = 0xFE;
	P2 = x;
	while(1)
	{
		if(l_pb==0) l_shift(x);
		if(r_pb==0) r_shift(x);
		delay(10);
	}
	//l_shift(x);
	//r_shift(x);
}

void delay(int count) { 
	int i,j; 
	for(i=0;i<count;i++)
	for(j=0;j<400;j++) if(l_pb&&r_pb&&s_pb==0) break;
}