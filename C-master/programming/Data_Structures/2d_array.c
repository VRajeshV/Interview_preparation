#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i , j;
    int **c;
    //static method
    int A[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //partially dynamic
    int *B[4];
    for(i = 0; i < 3; i++)
    {
        B[i] = (int *)malloc(4 * sizeof(int));
        for(j = 0; j < 4; j++)
        {
            B[i][j] = i + j;
        }
    }
    //fully dynamic
    c = (int **)malloc(sizeof(int *));
    for(i = 0; i < 3; i++)
    {
        c[i] = (int *)malloc(4 * sizeof(int));
        for(j = 0; j < 4; j++)
        {
            c[i][j] = i + j;
        }
    }
    printf("for A\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("for B\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

     printf("for C\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        free (B[i]);
    }
     for(i = 0; i < 3; i++)
    {
        free (c[i]);
    }
    free(c);
    return 0;
}