#include<stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type) 



/*long int my_sizeof(char *addr)
{
	return (char *)(&addr + 1) - (char *)&addr;
}*/
int main()
{
	int arr[4];
    int arr1[10];
	printf("%ld\n", my_sizeof(arr));

    printf("%ld\n", (char*) (&arr1+1) - (char*) (&arr1));
}