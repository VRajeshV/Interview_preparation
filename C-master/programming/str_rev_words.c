/*strrev of words*/
#include<stdio.h>
#include<string.h>

int find_len(char * s)
{
	int i = 0;

	while(s[i] != '\n')
		i++;
	return i;
}

void rev_str(char *s)
{
	int sI, eI, len, i, j;

	len = find_len(s);
	eI = len;
	for(i = len; i >= 0; i--)
	{
		if((s[i] == ' ') || (i == 0))
		{
			if(!i)
				sI = i;
			else
				sI = i + 1;
			for(j = sI; j<= eI; j++)
				printf("%c", s[j]);
			eI = i - 1;
			printf(" ");
		}
	}
}

int main()
{
	char arr[50];
	char i = 0;
	while(i < sizeof(arr))
	{
		arr[i] = '\0';
		i++;
	}
	i = 0;
	printf("enter the string1\n");
	fgets(arr, (sizeof(arr)), stdin);
	rev_str(arr);
	//printf("\n%s\n", arr);
	return 0;
}
