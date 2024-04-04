/*nCr = n!/((r!) * (n - r)!)*/
#include<stdio.h>

int fact(int n)
{
    if(n <= 1)
        return 1;
    else
        return n*fact(n - 1);
}

int combi(int n, int r)
{
    int t1, t2, t3;
    
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);
    return t1/(t2 * t3);
}

int combi_recur(int n, int r)
{
    if((n == r) || (r == 0))
        return 1;
    else
    {
        return (combi_recur(n - 1, r - 1) + combi_recur(n - 1, r));
    }
}

int main()
{
    printf("%d\n", combi(4, 2));
    printf("%d\n", combi_recur(4, 2));
    return 0;
}