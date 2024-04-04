#include<stdio.h>
#include<stdlib.h>

struct sll{
    int data;
    struct sll * next;
};

struct sll * rear;

void display_queue(struct sll * data)
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
        printf("queue is empty\n");
        return 1;
    }
    else
    {
        printf("queue is not empty\n");
        return 0;
    }    
}

void enqueue(struct sll ** p, int n)
{
    struct sll * node = malloc(sizeof(struct sll));

    node->data = n;
    node->next = NULL;
    if(rear)
    {
        rear->next = node;
        rear = node;
    }
    else
        *p = rear = node;

    display_queue(*p);
}

void dequeue(struct sll **p)
{
    if(!is_empty(*p))
    {
        struct sll * tmp = *p;
        *p = tmp->next;
        free(tmp);
    }
    display_queue(*p);
}

int main()
{
    int op, n;
    struct sll * p = rear = NULL;

    while(1)
    {
        printf("enter operations:\n"
        "1.enqueue\n"
        "2.dequeue\n"
        "3.exit\n");

        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("enter element\n");
                scanf("%d", &n);
                enqueue(&p, n);
                break;
            
            case 2:
                dequeue(&p);
                break;

            case 3:
                goto exit_loop;

            default:
                printf("invalid operation\n");
                break;
        }
    }

exit_loop:
        if(p)
            free(p);
    return 0;
}