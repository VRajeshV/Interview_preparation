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
    int n1, n2, n3;

    printf("enter integers:\n");
    scanf("%d%d", &n1, &n2);
    print_bits(n1);
    print_bits(n2);
    n3 = (n1 << 20) | n2;
    print_bits(n3);
    n1 = n3 >> 20;
    print_bits(n1);
    n2 = (n3 << 20) >> 20;
    print_bits(n2);
    return 0; 
}