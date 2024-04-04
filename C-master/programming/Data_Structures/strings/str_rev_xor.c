#include<stdio.h>
int find_len(char *a)
{
    int i = 0;
    //since we are using fgets, other wise cinditions should be: a[i] != '\0'
    while(a[i] != '\n')
        i++;
    return i;
}
int main()
{
    char a[50];
    int i, len;
    printf("enter the string\n");
    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        len = find_len(a);
        for(i = 0; i < (len/2); i++)
        {
            a[i] ^= a[len - i - 1];
            a[len - i - 1] ^= a[i];
            a[i] ^= a[len - i - 1];
        }
        printf("%s\n", a);
    }
    else
        perror("fgets:");
    return 0;
}