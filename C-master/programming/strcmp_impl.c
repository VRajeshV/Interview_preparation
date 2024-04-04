#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getlength(char *str)
{
//	printf("in %s\n", __func__);
	char *tmp = str;
	int len = 0;

	while(*tmp != '\0')
	{
		len++;
		tmp++;
	}
	return len;
}

void my_strcmp(char *str1, char *str2)
{
//	printf("in %s\n", __func__);
	char *tmp;
	int n1, n2, i = 0;

	n1 = getlength(str1);
	n2 = getlength(str2);

	if(n1 == n2)
	{
		while(*str1 != '\0' && *str2 != '\0')
		{
			if(*str1 == *str2)
			{
				str1++;
				str2++;
				i++;
			}
			else
				break;
		}
		if(i == n1)
			printf("%s:same\n", __func__);
		else
			printf("%s: not same: %d\n", __func__, (*str1 - *str2));
	}
	else
		printf("%s: not same: %d\n", __func__, *str1 - *str2);
}

int main()
{
	char buf1[20];
	char buf2[20];
	int ret;

	printf("enter string1:\n");
	fgets(buf1, sizeof(buf1), stdin);
//	scanf("%s", buf1);
	printf("enter string2:\n");
	fgets(buf2, sizeof(buf2), stdin);
//	scanf("%s", buf2);
	my_strcmp(buf1, buf2);
	ret = strcmp(buf1, buf2);
	if(!ret)
		printf("%s:same\n", __func__);
	else
		printf("%s: not same: %d\n", __func__, ret);	
	return 0;
}
