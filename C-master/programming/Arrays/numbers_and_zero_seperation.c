
/*array sorting and seperating zeros
For Eg: input array 0, 0, 1, 0, 2, 3, 5; output expected: 1, 2, 3, 5, 0, 0, 0*/
#include<stdio.h>

int main()
{
    int a[10], i, j, tmp;

    printf("enter array elements\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    i = 0;
    j = (sizeof(a)/sizeof(int) - 1);
    //for(i = 0, j = (sizeof(a)/sizeof(int)); i != j; i++, j--)
    while(i != j)
    {
        while(a[i])
            i++;
        while(!a[j])
            j--;
        if(i < j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
        else
            break;
    }
    for(i = 0; (a[i] && (i < 10)); i++)
    {
        for(j = i + 1; (a[j] && (j < 10)) ; j++)
        {
            if(a[i] > a[j])
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }    
        }
    }
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}