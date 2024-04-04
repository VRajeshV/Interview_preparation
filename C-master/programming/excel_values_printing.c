/*excel column values printing. this algo not comint too accurate. need to improve*/
#include<stdio.h>
#include<string.h>
#define MAX_CHAR 100
void strrev(char * str)
{
    int i = 0, len = 0;
    char tmp;

    while(str[len] != '\0')
        len++;
    len--;
    for(i = 0; i < (len/2); i++)
    {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
}

int main()
{
    int i, res, rem;
    char str[100];

    memset(str, '\0', MAX_CHAR);
    for(i = 1; i < MAX_CHAR; i++)
    {
        res = i;
       while(res > 0)
       {
           rem = res%26;
           if(!rem)
           {
               str[i - 1] = 'z';
               res = (res/26) - 1;
           }
           else
           {
               str[i - 1] = 'A' + rem - 1;
               res = res/26;
           }
       }
      // strrev(str);
       printf("%s\n", str);
    }
    return 0;
}