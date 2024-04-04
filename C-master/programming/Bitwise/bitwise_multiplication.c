/*bitwise multiplication*/
#include<stdio.h>

int mul_b(int x, int y)
{
    int res = 0;

    while(y)
    {
        if(y & 1)
            res += x;
        x = x<<1;
        y = y>>1;
    }

    return res;
}

int main()
{
    int a, b;

    printf("enter numbers\n");
    scanf("%d%d", &a, &b);
    printf("%d\n", mul_b(a, b));
    return 0;
}