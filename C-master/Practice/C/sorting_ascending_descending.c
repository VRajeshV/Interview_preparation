#include<stdio.h>
int main()
{
    int arr[5] = {4,3,5,2,1}, temp;

    for(int i = 0; i< 5 ; i++)
    {
        for(int j = i+1; j<5;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("ascedning \n");
    for(int i = 0; i< 5 ; i++)
    {
        printf(" %d ", arr[i]);
    }

    for(int i = 0; i< 5 ; i++)
    {
        for(int j = i+1; j<5;j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf(" \n descedning \n");
    for(int i = 0; i< 5 ; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf(" \n ");
}