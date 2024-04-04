/*longest palindromic string*/
#include<stdio.h>
#include<string.h>

int main()
{
    char str[50], str1[50];
    int len, i, j, tmp, tmp1, x, y, p_len = 0;

    printf("enter string:\n");
    fgets(str, sizeof(str), stdin);
    /*to getride of \n, which appended during fgets*/
    len = strlen(str) -1;
    for(i = 0; i < len; i++)
    {
       for(j = len - 1; j != i; j--)     
       {
           if(str[i] == str[j])
           {
               tmp = i;
               tmp1 = j;
               while(i != tmp1)
               {
                   if(str[++tmp] != str[--tmp1])
                    break;
               }
               if(i == tmp1)
               {
                   if((j - i) > p_len)
                   {
                        p_len = j - i;
                        x = i;
                        y = j;
                   }
               }
           }
       } 
    }
    for(i = x; i <= y; i++)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}