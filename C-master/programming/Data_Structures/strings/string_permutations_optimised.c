#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

// #define DEBUG(x) printf("%s: %d :" __FUNC__, __LINE__);\
//                  printf(x);
void swap(char * arr, int l, int i)
{
    char tmp;

    tmp = arr[l];
    arr[l] = arr[i];
    arr[i] = tmp;
}

void print_perm(char * in, int len)
{
    static int low;
    int i = low;

    if(low == (len - 1))
        printf("%s\n", in);
    else
    {
        while(i < len)
        {
            if(low != i)
                swap(in, low, i);
            low++;
            print_perm(in, len);
            low--;
            if(low != i)
               swap(in, low, i); 
            i++;
        }
    }
}
/*since taking inputs from fgets, assuming '\n' as termination character instead '\0'*/

int main()
{
    char a[50];
    int i, len;
    printf("enter the string. assuming input is less than 50 chars...\n");
    if(fgets(a, sizeof(a), stdin) != NULL)
    {
        printf("before call:\n");
        len = strlen(a);
        printf("length of the string %d\n", len);
        /*we are calculating lenght including \n. so subtracting 1 below*/
        print_perm(a, (len - 1));
    }
    else
        perror("fgets:");
    return 0;
}