/*finding missing elements in a sorted list*/
#include<stdio.h>

int main()
{
    int a[] = {1, 5, 6, 7, 8, 10};
    int diff = a[0];

    for(int i = 0; i < 6; i++)
    {
        if(a[i] - i != diff)
        {
            while(diff < (a[i] - i))
            {
                printf("%d ", diff + i);
                diff++;
            }
        }
    }

    return 0;
}