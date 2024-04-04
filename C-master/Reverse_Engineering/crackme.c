#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	scanf("%s", str);
	if(!strcmp(str, "hello"))
		printf("cracked\n");
	else
		printf("you wrong\n");
}
