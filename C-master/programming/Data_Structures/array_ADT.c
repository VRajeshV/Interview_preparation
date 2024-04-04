#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ArrayADT
{
    int *Arr;
    int size;
    int len;
};

void swap(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort_positive_negetive(struct ArrayADT * obj)
{
    int i, j;

    for(i = 0, j = (obj->len - 1); i < j; i++, j--)
    {
        while( (i < j) && (obj->Arr[i] < 0))
            i++;
        while((i < j) && (obj->Arr[j] >= 0))
            j--;
        if(i < j)
        {
            swap(&obj->Arr[i], &obj->Arr[j]);
        }
    }
}

void left_shift(struct ArrayADT * obj)
{
    int i = 0;

    for(i = 0; (i + 1)< obj->len; i++)
    {
        obj->Arr[i] = obj->Arr[i + 1];
    }
    obj->Arr[i] = 0;
}

void right_shift(struct ArrayADT * obj)
{
   int i = 0;

   for(i = obj->len - 1; i > 0; i--)
   {
        obj->Arr[i] = obj->Arr[i - 1];
   }
   obj->Arr[i] = 0;
}

void left_rotate(struct ArrayADT * obj)
{
    int i, tmp;

    tmp = obj->Arr[0];
    for(i = 0; (i + 1)< obj->len; i++)
    {
        obj->Arr[i] = obj->Arr[i + 1];
    }
    obj->Arr[obj->len - 1] = tmp;
}

void right_rotate(struct ArrayADT * obj)
{
   int i = 0, tmp;

   tmp = obj->Arr[obj->len - 1];
   for(i = obj->len - 1; i > 0; i--)
   {
        obj->Arr[i] = obj->Arr[i - 1];
   }
   obj->Arr[i] = tmp;
}

void reverse(struct ArrayADT * obj)
{
    int i, j;

    for(i = 0; i < (obj->len)/2; i++)
    {
        swap(&obj->Arr[i], &obj->Arr[(obj->len - i) - 1]);
    }
}

void Display(struct ArrayADT obj)
{
    int i;

    for(i = 0; i < obj.len; i++)
        printf("%d ", obj.Arr[i]);
    printf("\n");
}
/*here it is in recursive form, but we can write using loop too.
since it is a tail recursion, better to go with a loop*/
// int binary_search(int *arr, int l, int h, int num)
// {
//     int mid;

//     if(l > h)
//         return -1;
//     mid = (l + h)/2;
//     if(arr[mid] == num)
//         return mid;
//     else
//     {
//         if(arr[mid] > num)
//             h = mid - 1;
//         else
//             l = mid + 1;
//         binary_search(arr, l, h, num);
//     }
// }

int Linear_search(struct ArrayADT * obj, int num)
{
    int i;

    for(i = 0; i < obj->len; i++)
    {
        if(num == obj->Arr[i])
        {
            //Transposition 
            swap(&obj->Arr[i - 1], &obj->Arr[i]);
            //move to front
            //swap(&obj->Arr[i], &obj->Arr[0]);
            break;
        }
    }
    if(i != obj->len)
        return i;
    else
        return -1;
}

void Insert(struct ArrayADT * obj, int offset, int x)
{
    int i;

    if(offset < obj->size)
    {
        if((obj->len) < (obj->size))
        {
            for(i = (obj->size - 1); i > offset; i--)
            {
                obj->Arr[i] = obj->Arr[i - 1];
            }
            obj->Arr[offset] = x;
            obj->len++;
        }
        else
            printf("no space");
    }
    else
        printf("not a valid offset\n");
}

void Append(struct ArrayADT * obj, int x)
{
    if((obj->len) < (obj->size))
    {
        obj->Arr[obj->len] = x;
        obj->len++;
    }
    else
        printf("no space");
}

void delete_end(struct ArrayADT * obj)
{
    obj->len--;
}

void delete_at_index(struct ArrayADT * obj, int offset)
{
    int i;

    if(offset < (obj->len))
    {
        for(i = offset; (i + 1) < obj->len; i++)
        {
            obj->Arr[i] = obj->Arr[i + 1];
        }
        obj->len--;
    }
    else
        printf("invalid index");
};

int main()
{
    int Size, i, n, opt, index;
    struct ArrayADT obj;

    printf("enter size\n");
    scanf("%d", &Size);
    obj.Arr = (int *)malloc(Size*sizeof(int));
    obj.size = Size;
    memset(obj.Arr, 0, obj.size);
    if(obj.Arr)
    {
        obj.size = Size;
        obj.len = 0;
        while(1)
        {
            printf("1.append\n"
                   "2.print array\n"
                   "3.insert at an index\n"
                   "4.delete at end\n"
                   "5.delete at a position\n"
                   "6.Linear search\n"
                   "7.Reverse\n"
                   "8.Left Shift\n"
                   "9.Left rotate\n"
                   "10.Right shift\n"
                   "11.Right rotate\n"
                   "12.Sort pos neg\n");
                    
            printf("enter option\n");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1: printf("enter the value to append:\n");
                    scanf("%d", &n);
                Append(&obj, n);
                break;
            case 2: Display(obj);
                break;
            case 3: printf("enter the index\n");
                    scanf("%d", &index);
                    printf("enter the value\n");
                    scanf("%d", &n);
                    Insert(&obj, index, n);
                break;
            case 4: delete_end(&obj);
                break;
            case 5: printf("enter index to delete\n");
                    scanf("%d", &index); 
                delete_at_index(&obj, index);
                break;
            case 6: printf("enter number to search\n");
                    scanf("%d", &n); 
                printf("%d\n", Linear_search(&obj, n));
                break;
            case 7: reverse(&obj);
                    break;
            case 8: left_shift(&obj);
                    break;
            case 9: left_rotate(&obj);
                    break;
            case 10: right_shift(&obj);
                    break;
            case 11: right_rotate(&obj);
                    break;
            case 12: sort_positive_negetive(&obj);
                    break;
            default:printf("invalid option. try again...\n");
                break;
            }
        }
            free(obj.Arr);
    }
    else
    {
        perror("malloc:");
    }
    return 0;
}