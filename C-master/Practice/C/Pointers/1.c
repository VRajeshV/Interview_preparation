#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *p = NULL;
    p = malloc(10);
    char *ptr = 0x100;
    char **ptr1 = 0x100;
    strcpy(p,"abc");
    printf("%s \n",p);
    printf("%p \n",ptr);
    printf("%d \n",*ptr);
    ptr++;
    ptr1++;
    printf("%d \n",*ptr);
    printf("%p \n",ptr);
}