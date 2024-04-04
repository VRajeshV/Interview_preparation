#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int my_print(int n)
{
//	int fd = open(stdout, O_RDWR), i;
//	if(fd != -1)
//	{
		int i = write(1, ( char *)&n, strlen((char *)&n));
		if(i != sizeof(n))
			perror("write:");
//	}
//	else
//		perror("open:");
}

int main()
{
	my_print(4);
	return 0;
}
