#include "82GXX.H"

void test_led(void);
void delay_1ms(int count);
void disp_7_seg(int cnt_Digit,int cnt_Scan,int cnt_Delay,char Row_Point);

char code Column_Scan[4]={0x7F,0xBF,0xDF,0xEF};
char code Row_Data[10]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xD8,0x80,0x90};

char code Point_ON=0x7F,Point_OFF=0xFF;
char code Column_all_OFF=0xFF;//, Column_all_ON=0x00;

main()
{
	int cnt_Scan=0, cnt_Digit=0, cnt_Delay=300, d_Delay=3, cnt_1ms=0;
	char data Row_Point;
	//while(1)	disp_7_seg(1,2,3,4);//test_led(); // test all LED function
	/*
	while((cnt_Delay-=d_Delay) > d_Delay)
	{
		Row_Point=Point_OFF;
		for(cnt_Scan=0; cnt_Scan<4; cnt_Scan++)
		{
			disp_7_seg(cnt_Digit,cnt_Scan,cnt_Delay,Row_Point);
			if(++cnt_Digit==10) cnt_Digit=0;
		}
		Row_Point=Point_ON;
		for(cnt_Scan=3; cnt_Scan>-1; cnt_Scan--)
		{
			disp_7_seg(cnt_Digit,cnt_Scan,cnt_Delay,Row_Point);
			if(++cnt_Digit==10) cnt_Digit=0;
		}
	}
	*/
	cnt_Delay=d_Delay; cnt_Digit=0;
	
	while(1)
	{
		Row_Point=Point_OFF;
		while(cnt_Digit<10)
		{
			for(cnt_Scan=0; cnt_Scan<4; cnt_Scan++)
			{
				disp_7_seg((cnt_Scan+cnt_Digit)%10,cnt_Scan,cnt_Delay,Row_Point);
				if(++cnt_1ms==1000) { cnt_1ms=0; cnt_Digit++; }
			}
		}
		Row_Point=Point_ON;
		while(cnt_Digit>0)
		{
			for(cnt_Scan=0; cnt_Scan<4; cnt_Scan++)
			{
			disp_7_seg((cnt_Scan+cnt_Digit)%10,cnt_Scan,cnt_Delay,Row_Point);
			if(++cnt_1ms==1000) { cnt_1ms=0; cnt_Digit--; }
			}
		}
	}
}

void disp_7_seg(int cnt_Digit, int cnt_Scan, int cnt_Delay,char Row_Point)
{
	P0=Row_Data[cnt_Digit]&Row_Point;
	P2=Column_Scan[cnt_Scan];
	delay_1ms(cnt_Delay);
	P2=Column_all_OFF; // turn off all LEDs
}
/*
void test_led(void)
{
	int i;
	P0=0x00; // display "8."
	for(i=0;i<3;i++)
	{
		P2=Column_all_ON; delay_1ms(5000); // turn on all LEDs
		P2=Column_all_OFF; delay_1ms(5000); // turn off all LEDs
	}
}
*/
void delay_1ms(int count)
{
	int i,j;
	for(i=0;i<count;i++) for(j=0;j<400;j++);
}
