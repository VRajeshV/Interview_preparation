#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int x = 10;
int main()
{
	static int y;
	register int z;
	const int a = 10;
	int * b = (int *)&a;
	int c;
	volatile int w;
	char *str = "pavan";

	printf("%d\n", a);
	
	printf("pid:%d\n", getpid());
	getchar();
	printf("global variable addr:%p\n", &x);
	printf("static variable addr:%p\n", &y);
	printf("string literal addr:%p\n", str);
	printf("const variable addr:%p\n", &a);
	printf("volatile variable addr:%p\n", &w);
	printf("local variable addr:%p\n", &c);
	getchar();
	*b = 11;
	printf("%d\n", a);
	return 0;
}
