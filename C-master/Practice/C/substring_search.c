// C program to implement own strstr() function

#include <stdio.h>
#include <string.h>

char* StrStr(char* str, char* substr)
{
    static char* ptr;

    ptr = str;

    while (*ptr) {
        if (strncmp(ptr, substr, strlen(substr)) == 0)
            return ptr;
        ptr++;
    }
    return NULL;
}

int main()
{
    char str[32] = "India is great country";
    char* ptr;

    ptr = StrStr(str, "great");
    if (ptr != NULL)
        printf("String is: '%s'\n", ptr);
    else
        printf("Word 'great' is not found\n");

    ptr = StrStr(str, "power");
    if (ptr != NULL)
        printf("String is: %s\n", ptr);
    else
        printf("Word 'power' is not found\n");

    return 0;
}