// Filename : Seg_7.C
// Function : Common Anode 7-segment LEDs Display
// CPU : Megawin MG82Fx564
//
// Designed By Ray-Shine Run 2012/3/28
//****************************************************************
#include "82GXX.H"
//
//************************ functions *****************************
void test_led(void);
void delay_1ms(int count);
//
//************************ Parameter ****************************
//
unsigned char code data_7seg[16]=
{ 0xC0,0xFC,0x92,0x98,
0xAC,0x89,0x81,0xDC,
0x80,0x8C,0x84,0xA1,
0xB3,0xB0,0x83,0x87 };
//
//********************* Program Start *************************
//
main()
{
test_led();
while(1) P0=data_7seg[P1&0x0F];
}
void test_led(void)
{ int i;
for(i=0;i<10;i++)
{
P0=0x00; delay_1ms(1000); // turn on all LEDs
P0=0xFF; delay_1ms(1000); // turn off all LEDs
}
}
//-----------------------------------------------------------------
void delay_1ms(int count)
{ int i,j;
for(i=0;i<count;i++) for(j=0;j<250;j++);
}