#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

unsigned int linear_search(struct Array obj, int key)
{
	unsigned int index = -1;int i;
	
	for(i = 0; i < obj.length; i++)
	{
		if(obj.A[i] == key)
			break;
	}
	if(i != obj.length)
		index = i;
	return index;
}

void Display(struct Array obj)
{
    int i;

    for(i = 0; i < obj.length; i++)
        printf("%d ", obj.A[i]);
    printf("\n");
}

void append(struct Array * obj, int val)
{
	if(obj->length < obj->size)
	{
		obj->A[obj->length] = val;
		obj->length++;
	}
}

void insert(struct Array * obj, unsigned int index, int val)
{
    int i;
    //check for indexes which are not fit within size
    if(index >= obj->size)
    {
            printf("size not sufficient or invalid index\n");
    }
    else
    {
        for(i = obj->length; i != index; i--)
        {
            obj->A[i] = obj->A[i - 1];
        }
        obj->A[index] = val;
        obj->length++;
    }
}

void Delete(struct Array * obj, unsigned int index)
{
	int i;

	if(index < obj->length)
	{
		for(i = index; i < (obj->length - 1); i++)
		{
			obj->A[i] = obj->A[i + 1];
		}
		obj->length -= 1;	
	}
	else
		printf("invalid index");
}

int Array_sum(int *a, int n)
{
	int sum = 0, i;

	for(i = 0; i < n; i++)
		sum = sum + a[i];

	return sum;
}

int Array_sum_rec(int *a, int n)
{
	if(!n)
		return 0;

	return (a[n - 1] + Array_sum_rec(a, n - 1));
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6, 11, 200}, 20, 7};

    Display(arr);
    insert(&arr, 2, 10);
    Display(arr);
    append(&arr, 20);
    Display(arr);
    Delete(&arr, 3);
    Display(arr);
    printf("%d\n", linear_search(arr, 5));
    printf("%d\n", Array_sum(arr.A, arr.length));
    printf("%d\n", Array_sum_rec(arr.A, arr.length));
    return 0;
}
