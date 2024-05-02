// C program to check whether stack grows
// downward or upward.
#include<stdio.h>

void fun(int *main_local_addr)
{
	int fun_local;
	printf("\n %p \n",&fun_local);
	if (main_local_addr < &fun_local)
		printf("Stack grows upward\n");
	else
		printf("Stack grows downward\n");
}

int main()
{
	// fun's local variable
	int main_local;
	int main_local1;
	printf(" %p \n",&main_local);
	printf("\n %p \n",&main_local1);
	fun(&main_local);
	return 0;
}

