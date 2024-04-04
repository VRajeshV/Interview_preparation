#include<stdio.h>
#include<stdlib.h>

struct sll{
    int data;
    struct sll *next;
};

void display_stack(struct sll * data)
{
    struct sll * tmp = data;

    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

int is_empty(struct sll * data)
{
    if(!data)
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

void push(struct sll ** p, int n)
{
   struct sll * tmp = *p;

    struct sll * node = malloc(sizeof(struct sll));
    node->data = n;
    if(!*p)
        node->next = NULL;
    else
        node->next = *p;

    *p = node;
    display_stack(*p);
}

void pop(struct sll ** p)
{
    struct sll * tmp = *p;

    if(!is_empty(tmp))
    {
        printf("%d\n", tmp->data);
        *p = tmp->next;
        free(tmp);
    }
    display_stack(*p);
}

int main()
{
    int op, n;
    
    struct sll * head = NULL;
    
    while(1)
    {
        printf("enter operations:\n"
        "1.push\n"
        "2.pop\n"
        "3.isempty\n"
        "4.exit\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("enter element\n");
                scanf("%d", &n);
                push(&head, n);
                break;
            
            case 2:
                pop(&head);
                break;

            case 3:
                is_empty(head);
                break;
            
            case 4:
                goto exit_loop;

            default:
                printf("invalid operation\n");
                break;
        }
    }
    

exit_loop:
        if(head)
            free(head);
    return 0;
}