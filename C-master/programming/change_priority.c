#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

int main()
{	
	int ret;
	errno = 0;
	printf("i am: %d\n", getpid());
	ret = getpriority(PRIO_PROCESS, 0);
	if(ret != -1)
	{
		printf("priority is: %d\n", ret);
		getchar();
		printf("setting priority....\n");
		ret = setpriority(PRIO_PROCESS, 0, -30);
		if(ret != -1)
			printf("priority after changing: %d\n", getpriority(PRIO_PROCESS, 0));
		else
			perror("setpriority:");
	}
	else
		perror("getpriority:");
	getchar();
	while(1)
	{
	}
	return 0;
}
