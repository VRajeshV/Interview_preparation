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

void seperate_pos_neg(struct Array *obj)
{
	int i = 0, j = obj->length - 1, tmp;
	
	while(i < j)
	{
		while(obj->A[i] < 0)
			i++;
		while(obj->A[j] > 0)
			j--;
		if(i < j)
		{
			tmp = obj->A[j];
			obj->A[j] = obj->A[i];
			obj->A[i] = tmp;
		}
	}
}

int main()
{
    struct Array arr = {{}, 10, 0};
    int j;

    while(arr.length < arr.size)
    {
	    scanf("%d", &j);
	    arr.A[arr.length] = j;
	    arr.length++;
    }
    Display(arr);
    printf("+ve and -ve numbers seperation....\n");
    seperate_pos_neg(&arr);
    Display(arr);
    return 0;
}
