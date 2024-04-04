#include<stdio.h>

void print_bits_char(unsigned char n)
{
    int i, size;

    size = sizeof(n) * 8;
    for(i = size - 1; i >= 0; i--)
    {
        if(n & (1<<i))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

 void mirror_image(unsigned char n)
  {
    int i, size = sizeof(n) * 8;
	printf("before:\n");
	print_bits_char(n);
	for(i = 0; i < (size/2); i++)
	{
		if((n & (1<<i)) ^ (n & (1<<((size - i) - 1))))
		{
			n = n^(1<<i);
            n = n^(1<<((size - i) - 1));
		} 
	}
	printf("after:\n");
	print_bits_char(n);
	printf("%c\n", n);
  }

  int main()
  {
	  mirror_image('A');
	  return 0;
  }
