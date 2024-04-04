#include<stdio.h>

void print_bits(int num)
{
    int i;

    for(i = (8 * sizeof(int) - 1); i >= 0; i--)
    {
        if(num & (1<<i))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

void set_bit(int n, int pos)
{
    print_bits(n);
    n = n | (1<<pos);
    printf("set bit in position %d:\n", pos);
    print_bits(n);
}

void clear_bit(int n, int pos)
{
    print_bits(n);
    n = n & ~(1<<pos);
    printf("clear bit in position %d:\n", pos);
    print_bits(n);
}

void toggle_bit(int n, int pos)
{
    print_bits(n);
    n = n ^ (1<<pos);
    printf("toggle bit in position %d:\n", pos);
    print_bits(n);
}

void toggle_range(int n, int start, int end)
{
    print_bits(n);
    n = n ^ (((1<<(end - start + 1)) - 1)<<start);
    printf("toggled bits from position %d to %d:\n", start, end);
    print_bits(n);
}

void even_or_odd(int n)
{
    if(n & 1)
        printf("odd\n");
    else
        printf("even\n");
}

void clear_rightmost_setbit(int n)
{
    print_bits(n);
    n = n & (n - 1);
    printf("after clearing right most set bit:\n");
    print_bits(n);
}

void check_power_of_2(int n)
{
    if(n & (n - 1))
        printf("not a power of 2\n");
    else
        printf("power of 2\n");
}

void print_num_setbits(int n)
{
    int count = 0;

    print_bits(n);
    while(n)
    {
        count++;
        n &= n - 1;
    }
    printf("number of bits set: %d\n", count);
}

void swap_bits(int n, int i, int j)
{
    char bit1, bit2;

    print_bits(n);
    (1<<i & n)?(bit1 = 1):(bit1 = 0);
    (1<<j & n)?(bit2 = 1):(bit2 = 0);
    if(bit1 != bit2)
    {
        n ^= (1<<i);
        n ^= (1<<j);
    }
    print_bits(n);
}

void swap_even_odd_bits(int n)
{
    print_bits(n);
    int odd_bits = n & 0xAAAAAAAA;
    int even_bits = n & 0x55555555;
    n = (odd_bits >> 1) | (even_bits << 1); 
    print_bits(n);
}

int main()
{
    int n, opt, pos, pos1;

    printf("enter number:\n");
    scanf("%d", &n);
    print_bits(n);
    while(1)
    {
        printf("\n1.set bit\n"
               "2.clear bit\n"
               "3.toggle bit\n"
               "4.toggle range\n"
               "5.even or odd\n"
               "6.clear last right side set bit\n"
               "7.check whether power of 2\n"
               "8.number os set bits\n"
               "9.swap bits\n"
               "10.swap even and odd bits\n");

        printf("enter option:\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("enter position to set:\n");
            scanf("%d", &pos);
            set_bit(n, pos);
            break;
        
        case 2:
            printf("enter position to clear:\n");
            scanf("%d", &pos);
            clear_bit(n, pos);
            break;

        case 3:
            printf("enter position to toggle:\n");
            scanf("%d", &pos);
            toggle_bit(n, pos);
            break;

        case 4:
            printf("enter starting and ending positions to toggle:\n");
            scanf("%d%d", &pos, &pos1);
            toggle_range(n, pos, pos1);
            break;
        
        case 5:
            even_or_odd(n);
            break;
        
        case 6:
            clear_rightmost_setbit(n);
            break;

        case 7:
            check_power_of_2(n);
            break;

        case 8:
            print_num_setbits(n);
            break;

        case 9:
            printf("enter position of bits to swap\n");
            scanf("%d%d", &pos, &pos1);
            swap_bits(n, pos, pos1);
            break;

        case 10:
            swap_even_odd_bits(n);
            break;

        default: printf("invalid\n");
            break;
        }
    }
    return 0;
}