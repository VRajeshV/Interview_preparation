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
    int len, i, ref = 0, pos;

    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        len = find_len(a);
        for(i = 0; i < len; i++)
        {
            if((a[i] >= 'A') && (a[i] <= 'Z'))
                pos = a[i] - 'A';
            else if ((a[i] >= 'a') && (a[i] <= 'z'))
                pos = a[i] - 'a';
            if(ref & (1<<pos))
                printf("%c is duplicated\n", a[i]);
            else
                ref = ref | (1<<pos);
        }
    }
    else
        perror("fgets:");
    return 0;
}