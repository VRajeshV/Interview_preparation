#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char *p = NULL;
    p = malloc(10);
    strcpy(p,"abc");
    printf("%s \n",p);
}