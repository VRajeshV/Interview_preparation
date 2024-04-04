#include<stdio.h>

int main()
{
    int a[] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
    int dup = 0, count = 1, j;

    for(int i = 0; (i + 1) < 10; i++)
    {
        if(a[i] == a[i + 1])
        {
            if(a[i] != dup)
            {
                //printf("%d ", a[i]);
                dup = a[i];
                j = i + 1;
                while(a[j] == a[i])
                    j++;
                printf("%d is %d times\n", a[i], (j - i));
                i = j - 1;
            }
        }
    }

    return 0;
}