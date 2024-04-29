#include <stdio.h>
int main()
{
    int flag = 0;
    int data = 0;
    printf("Enter the number ");
    scanf("%d",&data); //Get the number
    flag = ((data != 0) && !(data & (data - 1))); // check the power of 2
    if(flag == 1)
    {
        printf("Number is a power of 2 \n");
    }
    else
    {
        printf("Enter number is not power of 2 \n");
    }
    return 0;
}