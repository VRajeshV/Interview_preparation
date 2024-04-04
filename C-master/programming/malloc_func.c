#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *ptr, * brk_val;
	
	printf("pid: %d\ncurrent programme break: %p\n", getpid(), sbrk(0));
	ptr = (char *)malloc(10);
	if(ptr != NULL)
	{
		getchar();
		printf("address allocated %p\n", ptr);
		printf("programme break after malloc: %p\n", sbrk(0));
		ptr[0] = 'c';
		getchar();
		free(ptr);
		printf("programme break after free: %p\n", sbrk(0));
	}
	else
		perror("malloc:");
	return 0;
}
