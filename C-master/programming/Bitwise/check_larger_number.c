/*number comparison using bitwise*/
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

void compare(int n1, int n2)
{
    int len; 
    
    len = (sizeof(int) * 8) - 1;
    while(len >= 0)
    {
        if(((1<<len) & n1) ^ ((1<<len) & n2))
            break; 
        len--;
    }
    if(len < 0)
        printf("equal\n");
    else if((1<<len) & n1)
        printf("%d is bigger\n", n1);
    else
        printf("%d is bigger\n", n2);
}

int main()
{
    int n1, n2;

    printf("enter numbers:\n");
    scanf("%d%d", &n1, &n2);
    print_bits(n1);
    print_bits(n2);
    compare(n1, n2);
    return 0;
}