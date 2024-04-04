#include<stdio.h>

void ins_sort(int * p, int n)
{
    int i, j, key;

    if(p)
    {
       for(i = 1; i < n; i++)
       {
            key = p[i];
            j = i - 1;
            while((j >= 0) && (p[j] > key))
            {
                p[j + 1] = p[j];
                j--;
            }
            p[j + 1] = key;
       }
    }
}

int main()
{
    int arr[10], i;

    printf("enter array:\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    ins_sort(arr, 10);
    for(i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}