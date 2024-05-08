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

    int num = 0x12345678;

int res = 0;

/*res = (num & 0x000000ff) << 24u;
res |= (num & 0x0000ff00) << 8u;
res|= (num & 0x00ff0000) >> 8u;
res|= (num & 0xff000000) >> 24u;*/

res = (0xff000000) & (num << 24);
res |= (0x00ff0000) & (num << 8);
res|= (0x0000ff00) & (num >> 8);
res|= (0x000000ff) & (num >> 24);

printf("%x \n", res);
}