#include<stdio.h>
#include<stdlib.h>

void swap(int * A, int i, int j)
{
    int tmp;

    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}
void quick_sort(int * a, int n)
{
    int pivot, i, j;

    if(n > 1)
    {
        pivot = a[0];
        i = 1;
        j = n - 1;
        if(i < j)
        {
            while(j > i)
            {
                while(a[i] < pivot && (i < n))
                    i++;
                while(a[j] > pivot && (j >= 0))
                    j--;
                if(j > i)
                    swap(a, i, j);
                else
                    break;
                i++;
                j--;
            }
            swap(a, 0, j);
            quick_sort(a, j);
            quick_sort(a + (j + 1), n - (j + 1));
        }
    }
}

int main()
{
    int n, *arr, i;

    printf("enter size\n");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));
    if(arr)
    {
        printf("enter elements\n");
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        quick_sort(arr, n);
        printf("sorted:\n");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    else
        perror("malloc:");
    return 0;
}