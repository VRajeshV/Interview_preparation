#include<stdio.h>


void fun(int n)
{
    if(n)
    {
        fun(n - 1);
        printf("%d ", n);
        
    }
}

int main()
{
    fun(5);
    return 0;
}