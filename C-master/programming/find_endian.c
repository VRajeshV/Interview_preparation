#include<stdio.h>
int main()
{
	unsigned int x = 0x1234;
	
	char *ptr = (char *)&x;

	printf("%p %u\n", ptr, *ptr++);
	printf("%p %u\n", ptr, *ptr++);
	printf("%p %u\n", ptr, *ptr++);
	printf("%p %u\n", ptr, *ptr);
	printf("only local change\n");
	return 0;
}
