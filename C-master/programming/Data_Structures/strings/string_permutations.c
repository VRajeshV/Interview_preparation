#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

// #define DEBUG(x) printf("%s: %d :" __FUNC__, __LINE__);\
//                  printf(x);
void print_out(char * in, char * tmp, char * out, int len)
{
    static int res_var;
    int i = 0;

    if(res_var == len)
        printf("%s\n", out);
    else
    {

        while(i < len)
        {
            if(!tmp[i])
            {
                out[res_var] = in[i];
                tmp[i] = 1;
                res_var++;
                print_out(in, tmp, out, len);
                res_var--;
                tmp[i] = 0;
            }
            i++;
        }
    }
}
/*since taking inputs from fgets, assuming '\n' as termination character instead '\0'*/
void print_perm(char * str, int k)
{
    static char * tmp = NULL, * out = NULL;

    if(!str || !k)
        printf("not a valid string\n");
    else
    {
        tmp = malloc(k);
        if(tmp)
        {
            out = malloc(k);
            if(out)
            {
                memset(tmp, 0, k);
                memset(out, 0, k);
                print_out(str, tmp, out, k);
                free(tmp);
                free(out);
            }
            else
            {
                perror("malloc for out:");
                free(tmp);
            }
        }
        else
            perror("malloc for tmp:");
    }
}

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