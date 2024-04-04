#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <execinfo.h>

int main()
{
	char *ptr, * brk_val
	;int i, j;
	char *buffer[100];
	char **str;

	printf("pid: %d\ncurrent programme break: %p\n", getpid(), sbrk(0));
	i = brk(sbrk(0) + 10);
	if(i)
	{
		perror("brk:");
		return -1;
	}
	ptr = sbrk(0);
//	ptr = (char *)malloc(10);
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
	
	j = backtrace((void **)buffer, 100);
        printf("number of addresses:%d\n", i);
        str = backtrace_symbols((void *const*)buffer, 100);
        while(i >= 0)
        {
                printf("%s\n", str[i]);
                i--;
        }
	return 0;
}
