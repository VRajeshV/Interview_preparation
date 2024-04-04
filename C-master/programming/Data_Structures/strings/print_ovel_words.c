#include<stdio.h>
#define NUM_OVELS 5 

int find_len(char * a)
{
    int i = 0;
/*since we are taking inputs from fgets, '/n' will get appended
so we are checking '\n' instead of '\0'*/
    while(a[i] != '\n')
        i++;
    return i;
}

unsigned char find_ovel(char x)
{
    int j;
    /*array of existing ovels*/
    char ovels[NUM_OVELS] = {'a', 'e', 'i', 'o', 'u'};
    unsigned char res = 0;

    for(j = 0; j < NUM_OVELS; j++)
    {
        if((x == ovels[j]) || (x == (ovels[j] - 32)))
        {
            res = 1;
            break;
        }
    }
    return res;
}

unsigned char find_ovel_cons_combo(char * str, int len)
{
    int ovel_c = 0, cons_c = 0, i;
    unsigned char res = 0;

    for(i = 0; i < len; i++)
    {
        if(((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z')))
        {
            if(find_ovel(str[i]))
                ovel_c++;
            else
                cons_c++;
        }
        if((ovel_c && cons_c))
        {
            res = 1;
            break;
        }
    }
    return res;
}

/*assuming input only having lower case characters. if not also, we can acheive the same by
adding a condition*/
int main()
{
    char a[50], tmp;
    int len, i, k = 0, ovel_c = 0, cons_c = 0, count = 0;

    printf("enter the string:\n");
    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        len = find_len(a);
        
        for(i = 0; i < len; i++)
        {
            if(((a[i] >= 'A') && (a[i] <= 'Z')) || ((a[i] >= 'a') && (a[i] <= 'z')))
            {
                if(find_ovel(a[i]))
                    ovel_c++;
                else
                    cons_c++;
                if((ovel_c && cons_c))
                {
                    /*finding whether remaining string satisfying the condition of beeing
                    the combination of both ovels and consonants*/
                    if(find_ovel_cons_combo(&a[i + 1], (len - (i + 1))))
                    {
                        tmp = a[i + 1];
                        a[i + 1] = '\0';
                        printf("%s\n", &a[k]);
                        a[i + 1] = tmp;
                    }
                    else
                        printf("%s\n", &a[k]);

                    ovel_c = 0;
                    cons_c = 0;
                    k = i + 1;
                    count++;
                }
            }
        }
        printf("total count of words: %d\n", count);
    }
    else
        perror("fgets:");

    return 0;
}