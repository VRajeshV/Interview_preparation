/*flip a bit*/
#include<stdio.h>

void print_bits(int n)
{
    int i, size;

    size = sizeof(n) * 8;
    for(i = size - 1; i >= 0; i--)
    {
        if(n & (1<<i))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

int main()
{
    int n, pos;

    scanf("%d", &n);
    scanf("%d", &pos);
    print_bits(n);
    n ^= (1<<pos);
    print_bits(n);
    return 0;
}