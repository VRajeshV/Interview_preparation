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
    char a[50], b[50];
    int len,len1, i, pos;
    int ref[26] = {0};

    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        if(fgets(b, sizeof(b), stdin) != NULL)
        {
            len = find_len(a);
            len1 = find_len(b);
            if(len == len1)
            {
                for(i = 0; i < len; i++)
                {
                    if((a[i] >= 'A') && (a[i] <= 'Z'))
                        pos = a[i] - 'A';
                    else if ((a[i] >= 'a') && (a[i] <= 'z'))
                        pos = a[i] - 'a';
                    ref[pos]++;
                }
                for(i = 0; i < len; i++)
                {
                    if((b[i] >= 'A') && (b[i] <= 'Z'))
                        pos = b[i] - 'A';
                    else if ((b[i] >= 'a') && (b[i] <= 'z'))
                        pos = b[i] - 'a';
                    ref[pos]--;
                    if(ref[pos] == -1)
                        break;
                }
                if(i == len)
                    printf("anagrams\n");
                else
                    printf("No\n");
            }
            else
                printf("No\n");
        }
        else
            perror("fgets b:");
    }
    else
        perror("fgets a:");
    return 0;
}