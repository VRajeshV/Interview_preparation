/*unsetting bits within a range in a number*/
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

void unset_bits(int n, int p1, int p2)
{
    int i, size, ref_n;

    //size = sizeof(n) * 8;
    ref_n = ((1<<(p1 - 1)) - 1) ^ ((1<<p2) - 1);
    print_bits(ref_n);
    n = n ^ ref_n;
    /*for(i = 0; i < size; i++)
    {
        if((i >= p1) && (i <= p2))
        {
            n = n & &(1<<i);
        }
    }*/
    print_bits(n);
}

int main()
{
    int n, pos1, pos2;

    printf("number:\n");
    scanf("%d", &n);
    printf("positions:\n");
    scanf("%d %d", &pos1, &pos2);
    print_bits(n);
    unset_bits(n, pos1, pos2);
    return 0;
}