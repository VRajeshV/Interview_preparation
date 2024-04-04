#include<stdio.h>
#include<string.h>
int main()
{
	char str[20];
	char pass[] = {'h', 'e', 'l', 'l', 'o'};
	
	scanf("%s", str);
	if(!strcmp(str, pass))
		printf("cracked\n");
	else
		printf("you wrong\n");
}
