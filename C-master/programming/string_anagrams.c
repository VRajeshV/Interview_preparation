#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int makeAnagram(char* a, char* b)
{

    int i, j, len1, len2, count = 0, count1 = 1, count2 = 0, index = 0;
    char *ptr = NULL;

    if(a && b)
    {
        len1 = strlen(a);
        len2 = strlen(b);
        if(len1 >= len2)
        {
            ptr = (char *)malloc(len1);
            memset(ptr, '\0', len1);
        }
        else
        {
            ptr = (char *)malloc(len2);
            memset(ptr, '\0', len2);
        }
        for(i = 0; i < len1; i++)
        {
            for(j = 0; j < index; j++)
            {
               if(ptr[j] == a[i])
                  break;
            }
            if(j != index)
                continue;
            for(j = i + 1; j < len1; j++)
            {
                if(a[i] == a[j])
                    count1++;
            }
            for(j = 0; j < len2; j++)
            {
                if(a[i] == b[j])
                    count2++;
            }
            (count1 > count2)?(count += (count1 - count2)):(count += (count2 - count1));
	    printf("%c %d %d\n", a[i], count1, count2);
            count1 = 1;
            count2 = 0;
            ptr[index++] = a[i];
        }
        for(i = 0; i < len2; i++)
        {
            for(j = 0; j < index; j++)
            {
               if(ptr[j] == b[i])
                  break;
            }
            if(j != index)
                continue;
            for(j = i + 1; j < len2; j++)
            {
                if(b[i] == b[j])
                    count1++;
            }
            for(j = 0; j < len1; j++)
            {
                if(b[i] == a[j])
                    count2++;
            }
            (count1 > count2)?(count += (count1 - count2)):(count += (count2 - count1));
	    printf("%c %d %d\n", a[i], count1, count2);
            count1 = 1;
            count2 = 0;
            ptr[index++] = b[i];
        }
    }

    free(ptr);
    return count;
}

int main()
{
	char str[100], str1[100];

	printf("enter strings\n");
	scanf("%s%s", str, str1);
	printf("%d\n", makeAnagram(str, str1));
	return 0;
}
