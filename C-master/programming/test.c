#include<stdio.h>
#include<stdlib.h>
int main()
{
	char * ptr = malloc(-10);
	printf("%p\n", ptr);
	return 0;
}
