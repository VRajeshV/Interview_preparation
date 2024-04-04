#include<stdio.h>
void printbits(unsigned int n)
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

int main()
{
	unsigned int x = 0x1234;

	printbits(x);
	return 0;
}
