#include<stdio.h>
#include<string.h>

char* stringrev(char *str)
{
    char tmp;
    int len = strlen(str);

    for (int i=0; i<len/2;i++)
    {
        tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
    return str;
}
int main()
{
    char a[] = "Hello";
    printf(" %s \n", stringrev(a));

}
