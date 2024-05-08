#include <stdio.h>

void fun(int *arr)
{
    int count = 0;
    int temp=0;
    //sort
    for(int i=0;i<10;i++)
    {
        for(int j=i;j<10;j++)
        {
            if(arr[i]>arr[j])
            {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
        }
    }
    printf("after sort\n");
    for(int i=0;i<10;i++)
    {
        printf(" %d ",arr[i]);
    }
    printf("\n ");
    count = 10;
    int index = 0,i;
    for(i=0;i<10;i++)
    {       
       for(int j=i+1;j<10;j++)
        {
            if(arr[i] == arr[j])
            {
                count--;
                i = j;
            }
        }
    }
    printf(" count %d \n",count);
}

int main()
{
    int arr[10] = {1,1,1,1,1,8,9,1,1,1};
    
    fun(arr);
    //printf("Hello World");

    return 0;
}
