#include<stdio.h>

void Display(int * a, int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void Reverse(int * a, int n)
{
	int i, l, tmp;
	
	for(i = 0; i <(n/2); i++)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
	}
}

void Rotate(int * a, int n, int r)
{
	int i, tmp;
	
	while(r)
	{
		tmp = a[0];
		for(i = 0; i < (n - 1); i++)
			a[i] = a[i + 1];
		a[n - 1] = tmp;
		r--;
	}
}

int main()
{
	int arr[] = {3, 1, 2, 10, 14, 20, 11};
	Display(arr, 7);
	Reverse(arr, 7);
	Display(arr, 7);
	Reverse(arr, 7);
	Display(arr, 7);
	Rotate(arr, 7, 2);
	Display(arr, 7);
	return 0;
}
