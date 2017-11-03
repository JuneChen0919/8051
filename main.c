#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <string.h>

void delay(int count);

char itobs(int n)		//顯示16進位 
{
	int i = 7, k = n, j;
	char s[8], g[9];
	
	while(i+1) {
		s[i--] = (1 & n) + '0';
		n >>= 1;
	}
	s[8] = '\0';
	
	for(j = 0; j < 4; j ++) g[j] = s[j];
	g[4] = ' ';
	for(j = 4; j < 8; j ++) g[j+1] = s[j];
	g[9] = '\0';
	
	printf("\n%d = %s\n", k, g);
	return 0;
}
 
void r_shift(int k)
{
	while(1)
	{
		k = k >> 1;
		k += 0x80;//128 
		if(k >= 0xFF) k = 0x7F;
		itobs(k);
		delay(500000);
		system("cls");
	}
	return 0;
}

void l_shift(int k)
{
	while(1)
	{
		k = k << 1;
		k ++;
		k -= 0x100;//256 
		if(k <= 0) k = 0xFE;
		itobs(k);
		delay(500000);
		system("cls");
	}
	return 0;
}

void stop()
{
	
}
 
int main(int argc, char** argv)
{
	system("color 0A");
	system("title \"標題\""); //default
	
	int i, x = 0xFE;	//起始值 
	//l_shift(x);			//左 
	r_shift(x);			//右 
	/*一次只能跑一個方向*/
	
	
	system("PAUSE"); //default
	system("cls");
	printf("\n");
	return 0;
}

void delay(int count) 
{ 
 int i,j; 
 for(i=0;i<count;i++) for(j=0;j<400;j++); 
}
