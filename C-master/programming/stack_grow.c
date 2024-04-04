// C program to check whether stack grows
// downward or upward.
#include<stdio.h>

void fun(int *main_local_addr)
{
	int fun_local;
	if (main_local_addr < &fun_local)
		printf("Stack grows upward\n");
	else
		printf("Stack grows downward\n");
}

int main()
{
	// fun's local variable
	int main_local;

	fun(&main_local);
	return 0;
}

