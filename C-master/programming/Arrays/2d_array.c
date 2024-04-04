#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a[3], i, j;

	a = (int *)malloc(12 * sizeof(int));//taking 3 rows and 4 columns
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			a[i][j] = i + j;
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			printf("%d", a[i][j]);
		printf("\n");
	}
	return 0;
}
