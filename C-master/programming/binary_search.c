#include<stdio.h>

int binary_search(int *a, int size, int key)
{
	int index = -1;
	int l = 0, h = size - 1, mid;

	while(l <= h)
	{
		mid = (l + h)/2;
		if(a[mid] == key)
		{
			index = mid;
			break;
		}
		else
		{
			if(a[mid] > key)
				h = mid - 1;
			else
				l = mid + 1;
		}
	}
	return index;
}

int binary_search_recursive(int *a, int l, int h, int key)
{
	int index = -1;

	int mid;
	if(l <= h)
	{
		mid = (l + h)/2;
		if(a[mid] == key)
			return mid;
		else
		{
			if(a[mid] < key)
				l = mid + 1;
			else
				h = mid - 1;
			index = binary_search_recursive(a, l, h, key);
		}
	}
	return index;	
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 10, 21, 34, 55};

	printf("%d\n", binary_search(arr, 9, 9));
	printf("%d\n", binary_search(arr, 9, 55));
	printf("%d\n", binary_search(arr, 9, 100));
	printf("recursive:\n");
	printf("%d\n", binary_search_recursive(arr, 0, 8, 9));
	printf("%d\n", binary_search_recursive(arr, 0, 8, 55));
	printf("%d\n", binary_search_recursive(arr, 0, 8, 100));
	return 0;
}
