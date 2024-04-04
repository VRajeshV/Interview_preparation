#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

void func(void)
{
	char buf[20] = {0};

	printf("buf start: %p\n and end: %p\n", buf, &buf[19]);
}

int main()
{
	int i = 0, j = 1;
	
	printf("hi pavan...i am %d\n", (int)getpid());
	printf("&i: %p\n&j: %p\n", &i, &j);
	getchar();
	func();
	getchar();
	return 0;
}
