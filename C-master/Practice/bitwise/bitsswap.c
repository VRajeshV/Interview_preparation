#include <stdio.h>
void SwapTwoNumber(int *a, int *b)
{
    if(*a == *b) // Check if the two addresses are same
        return;
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main()
{
    int x = 10;
    int y = 20;
    SwapTwoNumber(&x, &y);
    printf("x = %d and y = %d",x,y);
    return 0;
}
