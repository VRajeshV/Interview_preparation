#include<stdio.h>

void remove_spaces(char * arr)
{
    int i = 0, size = 0, j, var = 0;

    while(arr[i] != '\0')
    {
        size++;
        i++;
    }
    
    for(i = 0; i < size; i++)
    {
        if(arr[i] == ' ')
        {
            for(j = i + 1; ((arr[j] != ' ') && (j < size)); j++)
            {
                arr[(j - 1) - var] = arr[j];
            }
            
            i = j - 1;
            var++;
            size--;
            arr[size] = '\0';
        }    
    }
}

int main()
{
    char str[] = "hi pavan how are you";
    remove_spaces(str);
    printf("%s\n", str);
}