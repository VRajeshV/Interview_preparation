#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void display_stack(struct Stack data)
{
    int * tmp = data.S, i;

    if(tmp)
    {
        for(i = 0; i <= (data.size) - 1; i++)
            printf("%d ", tmp[i]);
        printf("\n");
    }
}

int is_full(struct Stack data)
{
    if(data.top == 0)
    {
        printf("stack is full\n");
        return 1;
    }
    else
    {
        printf("stack is not full\n");
        return 0;
    }
}

int is_empty(struct Stack data)
{
    if(data.top == data.size - 1)
    {
        printf("stack is empty\n");
        return 1;
    }
    else
    {
        printf("stack is not empty\n");
        return 0;
    }    
}

void push(struct Stack * p, int n)
{
    if(!is_full(*p))
    {
        p->S[p->top] = n;
        p->top--;
    }

    display_stack(*p);
}

void pop(struct Stack * p)
{
    if(!is_empty(*p))
    {
        p->top++;
        printf("%d\n", p->S[p->top]);
        p->S[p->top] = '\0';
    }
    display_stack(*p);
}

void peek(struct Stack data, int index)
{
    if(data.top > index)
        printf("no element in that index\n");
    else
        printf("%d\n", data.S[data.top]);
    
    display_stack(data);
}

int main()
{
    int op, n;
    struct Stack obj;

    printf("enter stack size needed:\n");
    scanf("%d", &obj.size);
    obj.S = malloc((obj.size) * sizeof(int));
    if(obj.S)
    {
        memset(obj.S, '\0', obj.size);
        obj.top = obj.size - 1;
        while(1)
        {
            printf("enter operations:\n"
            "1.push\n"
            "2.pop\n"
            "3.peek\n"
            "4.isempty\n"
            "5.isfull\n"
            "6.exit\n");

            scanf("%d", &op);

            switch (op)
            {
                case 1:
                    printf("enter element\n");
                    scanf("%d", &n);
                    push(&obj, n);
                    break;
                
                case 2:
                    pop(&obj);
                    break;

                case 3:
                    printf("enter index\n");
                    scanf("%d", &n);
                    peek(obj, n);
                    break;

                case 4:
                    is_empty(obj);
                    break;
                
                case 5:
                    is_full(obj);
                    break;

                case 6:
                    goto exit_loop;

                default:
                    printf("invalid operation\n");
                    break;
            }
        }
    }
    else
        perror("malloc:");

exit_loop:
        if(obj.S)
            free(obj.S);
    return 0;
}