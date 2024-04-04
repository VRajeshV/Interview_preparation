#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>

static bool overflow = false;
static unsigned int stack_size;
static unsigned int stack_limit;

void handler(int signum)
{
	printf("handler called\n");
	overflow = true;	
}
void recurse()
{
	if(overflow == true)
	{
		printf("stack overflow detected. returning....\n");
		exit(1);
	}	
	int x = 10;
	recurse();
}

int main()
{
	struct rlimit limit;
	int ret;

	memset(&limit, 0, sizeof(limit));
	ret = getrlimit(RLIMIT_STACK, &limit);
	if(!ret)
	{ 
		stack_size = (unsigned int)rlimit.rlimit_cur;
	}
	else
		perror("getrlimit:");	
//	signal(SIGSEGV, handler);
//		perror("siganl:");
	recurse();
//	printf("waiting for signal\n");
//	getchar();
	return 0;
}
