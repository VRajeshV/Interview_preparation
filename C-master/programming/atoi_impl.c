#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int getlength(char *str)
{
	int n = 0;
	char *tmp = str;

	if(str != NULL)
	{
		while(*tmp != '\0')
		{
			tmp++;
			n++;
		}
	}
	else
		n = 0;
	return n;
}

int my_atoi(char *num)
{
	int n = 0, len, i;
	char *tmp;

	tmp = num;
	if(num != NULL)
	{
		len = getlength(num);
		for(i = len - 1; i >= 0; i--)
		{
			if(((*tmp - '0') >= 0) && ((*tmp - '0') <= 9))
			{
				n = n + (pow(10, i) * (*tmp - '0'));
				tmp++;
			}
			else
				break;
		}
	}
	else
		n = -1;
	return n;	
}

int main()
{
	char buf[10];
	
	printf("enter string num:\n");
	scanf("%s", buf);
	printf("library_func:%d\n", atoi(buf));
	printf("my_func:%d\n", my_atoi(buf));
	return 0;
}
