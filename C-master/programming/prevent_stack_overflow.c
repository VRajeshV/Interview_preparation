#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

static long unsigned int stack_limit;
static int times = 1;
static int call_num;
static char * stack_initial_addr;

void recursive(void)
{
	char c;long unsigned int allocated;

	allocated = stack_initial_addr - &c;
	if(allocated >= (stack_limit - (132 * 1024)))
	{
		printf("stack reached maximum...can't allocate more\n");
		return;
	}
	printf("Times:%d %p allocated: %lu\n", times++, &c, allocated);
	recursive();
}

int main()
{
	char c = 0;
	struct rlimit limit;
	int ret;
	printf("i am: %d\n", getpid());
	stack_initial_addr = &c;
	ret = getrlimit(RLIMIT_STACK, &limit);
	if(ret != -1)
        {
                stack_limit = limit.rlim_cur;
                printf("soft limit: %lu\n", stack_limit);
                printf("hard limit: %lu\n", limit.rlim_max);
                getchar();
        }
        else
                perror("getrlimit:");
	printf("stack address: %p\n", stack_initial_addr);
	getchar();
	printf("enter number of times the recursive function should get called\n");
	scanf("%d", &call_num);
	recursive();
	getchar();
	return 0;
}
