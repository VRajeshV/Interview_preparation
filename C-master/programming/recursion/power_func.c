#include<stdio.h>

int my_pow(int x, int y)
{
    if(!y)
        return 1;
    if(y%2)
        return my_pow((x * x), (y - 1)/2) * x;
    else
        return my_pow(x * x, y/2);
}

int main()
{
    printf("%d\n", my_pow(2, 5));
    return 0;
}