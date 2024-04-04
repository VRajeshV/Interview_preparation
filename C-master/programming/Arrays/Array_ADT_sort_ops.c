#include<stdio.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void Display(struct Array obj)
{
    int i;

    for(i = 0; i < obj.length; i++)
        printf("%d ", obj.A[i]);
    printf("\n");
}

void insert(struct Array * obj, int val)
{
	int i, j, tmp;

	if((obj->length) < (obj->size))
	{
		for(i = (obj->length - 1); i >= 0; i--)
		{
			if(val >= (obj->A[i]))
			{
				for(j = obj->length; j > (i + 1); j--)
					obj->A[j] = obj->A[j - 1];
				obj->A[j] = val;
				break;	
			}
			else
			{
				if(!i)
				{
					for(j = obj->length; j > i; j--)
						obj->A[j] = obj->A[j - 1];
					obj->A[j] = val;
					break;
				}
			}
		}
		obj->length++;
	}
	else
		printf("not having enough size array\n");
}

void sort(struct Array * obj)
{
	int i, j, tmp;

	for(i = 0; i < obj->length; i++)
	{
		for(j = i + 1; j < obj->length; j++)
		{
			if((obj->A[i]) > (obj->A[j]))
			{
				tmp = obj->A[i];
				obj->A[i] = obj->A[j];
				obj->A[j] = tmp;
			}
		}
	}
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6, 11, 200}, 20, 7};

    Display(arr);
    sort(&arr);
    printf("sorted...\n");
    Display(arr);
    printf("inserting 20...\n");
    insert(&arr, 20);
    Display(arr);
    printf("inserting 2000...\n");
    insert(&arr, 2000);
    Display(arr);
    printf("inserting 1...\n");
    insert(&arr, 1);
    Display(arr);
    printf("inserting 7...\n");
    insert(&arr, 7);
    Display(arr);
    return 0;
}
