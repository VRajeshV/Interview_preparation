#include<stdio.h>

void reversestring(char* begin,char* end)
{
    char temp;
    while(begin <end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
void reversewords(char *str)
{
    char *word_begin = str;

    // boundary
    char *temp = str;

    while(*temp)
    {
        temp++;
        if(*temp == '\0')
        {
            reversestring(word_begin,temp -1);
            printf("null loop");
            printf("\n %s \n", word_begin);
        }
        else if(*temp == ' ')
        {
            reversestring(word_begin, temp -1);
            printf("space loop");
            printf("\n %s \n", word_begin);
            word_begin = temp + 1 ;
        }
    }
    printf("\n %s \n", str);
    reversestring(str , temp -1);
    printf("after \n %s \n", str);
}

int main()
{
    char a[] = " I am the Great";
    reversewords(a);
}