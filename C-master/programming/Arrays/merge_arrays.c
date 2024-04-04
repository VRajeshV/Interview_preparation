//merging two sorted arrays
#include<stdio.h>

void display(int * a, int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void merge(int * A, int n, int * a, int n1, int * b, int n2)
{
	int i = 0, j = 0, k = 0;

	while(k < n)
	{
		A[k++] = (a[i] < b[j])?(a[i++]):(b[j++]);
		if((i != n1) && (j != n2))
		{
			continue;
		}
		else if(i == n1)
		{
			while(j < n2)
				A[k++] = b[j++];
		}
		else
		{
			while(i < n1)
				A[k++] = a[i++];
		}
	}
}

int main()
{
	int a1[5] = {1, 2, 3, 4, 5};
	int a2[6] = {6, 7, 8, 9, 10, 11};
	int A[11];

	display(a1, 5);
	display(a2, 6);
	merge(A, 11, a1, 5, a2, 6);
	display(A, 11);
	
	return 0;
}
