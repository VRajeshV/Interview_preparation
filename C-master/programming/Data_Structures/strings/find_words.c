#include<stdio.h>

int find_len(char * a)
{
    int i = 0;

    while(a[i] != '\0')
        i++;
    return i;
}

int main()
{
    char a[50];
    char i = 0;
    int len, count = 0;

    printf("enter the string:\n");
    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        //len = find_len(a);

        for(i = 0; a[i] != '\0'; i++)
        {
            if(a[i] == ' ')
            {
                if(i)
                {
                    /*second condtions only applicable if input string consists '\n' as the
                    last character*/
                    if((a[i + 1] != '\0') && (a[i + 1] != '\n'))
                    {
                        if(a[i - 1] != ' ')
                            count++;
                    }
                    else
                        count--;
                }
            }
        }
        printf("%d\n", ++count);
    }
    else
        perror("fgets:");
    return 0;
}