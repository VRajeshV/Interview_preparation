#include<stdio.h>
#include<stdlib.h>
#include <execinfo.h>
int main()
{
	char *buffer[100];
	char **str;int i;
	char * ptr = (char *)malloc(100);
	if(ptr != NULL)
	{
		ptr[0] = 'c';
		free(ptr);
	}
	else
		perror("malloc:");
	i = backtrace((void **)buffer, 100);
	printf("number of addresses:%d\n", i);
	str = backtrace_symbols((void *const*)buffer, 100);
	while(i >= 0)
	{
		printf("%s\n", str[i]);
		i--;
	}
	return 0;
}
