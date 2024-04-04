//diagonal matrix
#include<stdio.h>

struct matrix
{
    int arr[10];
    int size;
};

void set_ele(struct matrix * obj, int i, int j, int e)
{
    if(i == j)
        obj->arr[i - 1] = e;
}

int get_ele(struct matrix * obj, int i, int j)
{
    if(i == j)
        return obj->arr[i - 1];
    else
        return -1;
}

int main()
{
    struct matrix obj;

    set_ele(&obj, 1, 1, 5);
    printf("%d\n", get_ele(&obj, 1,1));
    return 0;
}