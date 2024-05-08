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

char* stringrev1(char *str)
{
    char tmp;
    int end = strlen(str) - 1;
    int start = 0; 

    while (end > start) { 
        
        tmp=  str[end];
        str[end--] = str[start];
        str[start++] = tmp;
    } 
      
    return str;
}

int main()
{
    char a[] = "Hello";
    //printf(" %s \n", stringrev(a));
    printf(" %s \n", stringrev1(a));

}
