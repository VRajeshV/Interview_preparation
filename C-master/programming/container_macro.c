#include<stdio.h>

#define my_container(ptr, type, member) ({\
const typeof(((type *)0)->member)* __mptr = ptr;\
(type *)((char *)__mptr - (&((type *)0)->member));\
})
int main()
{
	//int x = ({1; 2;}) + 3;
	//printf("%d\n", x);
	//int x = 5;
	//typeof(x) y = 6;
	//printf("%d %d\n", x, y);
	struct s {
        	char m1;
        	char m2;
	};

	/* This will print 1 */
	struct s obj;
	printf("%p\n", &obj);
	printf("%p\n", (char *)&obj.m2 - &((struct s *)0)->m2);
	printf("%p\n", my_container(&obj.m2, struct s, m2));
	//printf("%d\n", &((struct s*)0)->m2);
	return 0;
}
