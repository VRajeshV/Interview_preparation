
#include<stdio.h>

int main()
{
    int a = 20,b=10;
    int resultmin,resultmax; 
    resultmin = b ^ ((a ^ b) & -(a < b)); // min(a, b)
    
    resultmax = a ^ ((a ^ b) & -(a < b)); // max(a, b)


    printf("resultmin %d\n",resultmin);
    printf("resultmax %d\n",resultmax);
}