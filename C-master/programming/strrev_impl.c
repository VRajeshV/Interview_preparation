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
	printf("%s:entered string length: %d\n", __func__, len);
	return len;
}

void my_strrev(char *str)
{
	int n, i;
	char tmp;
//	printf("in %s\n", __func__);
	if(str != NULL)
	{
		n = getlength(str);
	//	if(n%2)
			
		for(i = 0; i < n/2; i++)
		{
			tmp = str[i];
			str[i] = str[n - i - 1];
			str[n - i - 1] = tmp;
		}
		printf("%s\n", str);	
	}
	else
		printf("not a proper string\n");

}

int main()
{
	char buf1[20];
	int ret;

	printf("enter string:\n");
	fgets(buf1, sizeof(buf1), stdin);
	printf("%s:entered string length: %d\n", __func__, (int)strlen(buf1));
	my_strrev(buf1);
	return 0;
}
