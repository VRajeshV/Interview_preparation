#include <stdio.h>
int main()
{
    int num, i = 0, next, preValue1 = 0, preValue2 = 1;
    printf("Enter no. of terms: ");
    scanf("%d",&num);
    if(num < 0)
    {
        printf("Enter valid number\n");
    }
    else
    {
        while(i < num)
        {
            if(i <= 1)
            {
                next = i;
            }
            else
            {
                next = preValue1 + preValue2;
                preValue1 = preValue2;
                preValue2 = next;
            }
            printf("%d \t", next);
            i++;
        }
    }
    return 0;
}