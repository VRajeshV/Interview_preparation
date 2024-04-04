#include<stdio.h>
void inline add(int, int) __attribute__((always_inline));
int main()
{
	add(3, 4);
	return 0;
}

void inline add(int a, int b)
{
	printf("%d\n", a + b);
}
