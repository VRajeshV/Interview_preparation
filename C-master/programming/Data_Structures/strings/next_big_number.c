#include<stdio.h>
#include<string.h>

int get_num(char * str)
{
    int i, mul = 1, num = 0, len;

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        num = num + (str[i] - '0')* mul;
        mul *= 10;
    }
    return num;
}

int main()
{
    char str[10], tmp;
    int i, j, diff = 0, len, num, num1;

    printf("enter the number\n");
    scanf("%s", str);
    len = strlen(str);
    num = get_num(str);

    for(i = len - 1; i >= 0; i--)
    {
        str[i] - '0';
        j = 0;
        while(j < len)
        {
            if((tmp == str[j]) && (i != j))
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
                num1 = get_num(str);
                if(diff > (num1 - num))
                    diff = num1 - num;
                break;
            }
            j++;
        }
    }
    printf("%d\n", num + diff);
    return 0;
}