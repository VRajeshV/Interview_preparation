#include<stdio.h>
#include<stdlib.h>

void merge(int * A, int l, int high)
{
    int * tmp, i, j, k, mid;
    
    tmp = malloc((high + 1) * sizeof(int));
    if(tmp)
    {
        mid = (l + high)/2;
        i = l;
        j = mid + 1;
        k = 0;

        while((i <= mid) && (j <= high))
        {
            if(A[i] > A[j])
                tmp[k++] = A[j++];
            else
                tmp[k++] = A[i++];
        }
        while(i <= mid)
            tmp[k++] = A[i++];
        while(j <= high)
            tmp[k++] = A[j++];
        j = 0;
        for(i = l; i <= high; i++)
            A[i] = tmp[j++];

        free(tmp);
    }   
    else
        perror("malloc:"); 
}

void sort_it(int * A, int l, int h)
{
    int mid;

    if(l < h)
    {
        mid = (l + h)/2;
        if(mid)
        {
            sort_it(A, l, mid);
            sort_it(A, mid + 1, h);
        }
        merge(A, l, h);
    }
}

int main()
{
    int i, n, * arr;

    printf("enter number of elements:\n");
    scanf("%d", &n);
    arr = malloc(n * sizeof(int));
    if(arr)
    {
        printf("enter elements:\n");
        for(i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort_it(arr, 0, n - 1);
        printf("after sorting:\n");
        for(i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        free(arr);
    }
    else
        perror("malloc:");
    return 0;
}