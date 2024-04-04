//we can do merging only on sorted arrays

#include<stdio.h>
#include<stdlib.h>

int * merge(int * a1, int * a2)
{
    int * p, i, j, k;

    p = (int *)malloc(10 * sizeof(int));
    for(i = 0, j = 0, k = 0; ((i < 5) && (j < 5)); k++)
    {
        if(a1[i] < a2[j])
        {
            p[k] = a1[i++];
        }
        else
        {
            p[k] = a2[j++];
        }
    }
    if(i < 5)
    {
        while(i < 5)
        {
            p[k++] = a1[i++];
        }
    }
    else
    {
        if(j < 5)
        {
             while(i < 5)
            {
                p[k++] = a1[j++];
            }   
        }
    }
    return p;
}

int main()
{
    int arr1[5] = {3, 8, 16, 20, 25};
    int arr2[5] = {4, 10, 12, 22, 23}, i, *ptr;

    ptr = merge(arr1, arr2);

    for(i = 0; i < 10; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);

    return 0;
}