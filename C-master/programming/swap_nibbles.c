#include<stdio.h>

void printbits(int n)
{
	int i = (sizeof(n) * 8) - 1;
	while(i >= 0)
	{
		if(n & (1<<i))
			printf("1 ");
		else
			printf("0 ");
		i--;
	}
	printf("\n");
}

void swap_nibble(int n)
{

	n =(n&0xFFFFFF00) | ((((n&0xF)<<4)|(n&0xF0)>>4));
	printf("swapped:\n");
	printbits(n);
}

int main()
{
	int i;
	
	printf("enter the number:\n");
	scanf("%d", &i);
	printbits(i);
	swap_nibble(i);
	return 0;
}
