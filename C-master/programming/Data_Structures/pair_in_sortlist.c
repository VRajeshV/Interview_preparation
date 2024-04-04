//finding out pair of elements which sum is 10
#include<stdio.h>

int main()
{
    int a[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, i = 0, j = 9, sum;

    while(i < j)
    {

        sum = a[i] + a[j];
        if(sum == 10)
        {
           printf("%d %d\n", a[i], a[j]);
           i++;
           j--;
        }    
        else
        {
            if(sum < 10)
                i++;
            else
                j--;
        }
    }
    return 0;
}