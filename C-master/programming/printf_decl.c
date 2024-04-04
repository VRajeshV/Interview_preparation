#include<stdio.h>
#include<stdarg.h>

/*int my_print(int num, ...)
{
	va_list list;
	int i;

	printf("num: %d\n", num);
	va_start(list, num);
	for(i = 0; i < num; i++)
	{
		printf("%d ", va_arg(list, int));
	}
	printf("\n");	
	va_end(list);
	return i;
}*/
char *convert(int num, int base)
{
        char num_conv[]="0123456789ABCDEF";
        static char buff[20];
        char * ptr;

        ptr = &buff[19];
        *ptr = '\0';

        do{
                *--ptr = num_conv[num%base];
                num /= base;
        }while(num != 0);

//      	printf("from convert: %s\n", ptr);
        return ptr;
}

int my_printf(char *fmt, ...)
{
	unsigned int i;
	va_list list;
	char * input;

	va_start(list, fmt);
	for(input = fmt; *input != '\0'; input++)
	{
		while((*input != '\0') && (*input != '%'))
		{
			putchar(*input);
			input++;
		}
		input++;

		switch(*input)
		{
			case 'c': i = va_arg(list, int);
				  putchar(i);
				  break;	
			case 'd': i = va_arg(list, int);
				  puts(convert(i, 10));
				  break;	
		}
	}
	va_end(list);
	return 0;
}

int main()
{
	volatile int x = 10;

//	my_print(2, 30, 100);
	my_printf("values are:%d %d\n", 20, 30);
	return 0;
}
