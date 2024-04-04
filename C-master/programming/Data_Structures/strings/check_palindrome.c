#include<stdio.h>

int find_len(char * a)
{
    int i = 0;
//since we are taking inputs from fgets, '/n' will get appended
//so we are checking
    while(a[i] != '\n')
        i++;
    return i;
}

int main()
{
    char a[50];
    int len, i;

    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        len = find_len(a);
        for(i = 0; i < (len/2); i++)
        {
            if(a[i] != a[len - 1 - i])
                break;
        }
        if(i == (len)/2)
            printf("palindrome\n");
        else
            printf("not\n");
    }
    return 0;
}