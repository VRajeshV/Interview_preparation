#include<stdio.h>

int taylor(int x, int n)
{
    static int p = 1, f = 1;
    double r;

    if(!n)
        return 0;
    else
    {
        r = taylor(x, (n - 1));
        p *= x;
        f *= n;
        return r + (p/f);    
    }
}

int main()
{
    printf("%d\n", taylor(3, 4));
    return 0;
}