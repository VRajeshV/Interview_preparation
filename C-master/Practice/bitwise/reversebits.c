#include<stdio.h>


#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS)
//bit reversal function
unsigned int ReverseTheBits(unsigned int num)
{
    unsigned int iLoop = 0;
    unsigned int tmp = 0;         //  Assign num to the tmp
    int iNumberLopp = INT_BITS;
    for(; iLoop < iNumberLopp; ++iLoop)
    {
        if((num & (1 << iLoop))) // check set bits of num
        {
            tmp |= 1 << ((INT_BITS - 1) - iLoop); //putting the set bits of num in tmp

            //tmp |= 1 << ((INT_BITS - 1) - iLoop);
        }
    }
    return tmp;
}

int print(int num)
{
    for(int iLoop =0; iLoop < INT_BITS; ++iLoop)
    {
        if(num & 1<<iLoop)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

int main()
{
    int rev = ReverseTheBits(10);

    printf("before reverse \n");
    print(10);
    printf("\nafter reverse \n");
    print(rev);
    printf("\n");


}