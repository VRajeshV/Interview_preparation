#include<stdio.h>

// little endian - last byte of binary representation of the multibyte data-type is stored first
// big endian - first byte of binary representation of the multibyte data-type is stored first

int main()
{
    unsigned int i = 1;

    char *c = (char *)&i;
    if(*c)
    {
        printf("little indian \n");
    }
    else
    {
        printf("big indian \n");
    }
}