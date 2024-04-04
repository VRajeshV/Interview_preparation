#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

void printlimits(int resource)
{
	struct rlimit limit;
	int ret;

	ret = getrlimit(resource, &limit);
	if(!ret)
	{
		printf("soft: %lu\n", (unsigned long)limit.rlim_cur);
		printf("hard: %lu\n", (unsigned long)limit.rlim_max);
	}
	else
		perror("getrlimits:");
}

int main()
{
	int ret;
	struct rusage in_use;

	printf("for stack:\n");
	printlimits(RLIMIT_STACK);

/*	ret = getrusage(RUSAGE_SELF, &in_use);
	if(!ret)
	{
		
	}
	else
		perror("getrusage:");*/
	return 0;
}
