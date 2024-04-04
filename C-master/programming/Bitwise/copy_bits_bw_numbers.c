/*copy bits from a number to another number*/
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
void copy_bits(int s, int d, int p1, int p2)
{
    int i, ref_n, tmp, size;

    ref_n = ((1<<(p1 - 1)) - 1) ^ ((1<<p2) - 1);
    printf("ref_n :\n");
    print_bits(ref_n);
    tmp = ref_n;
    ref_n &= s;
    printf("bits extracted from source\n");
    print_bits(ref_n);
    
    d &= ~tmp;
    d |= ref_n;
    /*size = sizeof(int) * 8;
    for(i = 0; i < size; i++)
    {
        if((i >= p1) && (i <= p2))
        {
            if((s & (1<<i) ) != (d & (1<<i)))
            {
                d ^= (1<<i);
            }
        }
    }*/
   // print_bits(s);
    print_bits(d);
}
int main()
{
    int n1, n2, p1, p2;

    printf("enter numbers and positions\n");
    scanf("%d %d %d %d", &n1, &n2, &p1, &p2);
    print_bits(n1);
    print_bits(n2);
    copy_bits(n1, n2, p1, p2);
    return 0;
}