#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void display_queue(struct queue data)
{
    int * tmp = data.Q, i;

    if(tmp)
    {
        for(i = (data.front + 1); i <= data.rear; i++)
            printf("%d ", tmp[i]);
        printf("\n");
    }
}

int is_full(struct queue data)
{
    if(data.rear == (data.size - 1))
    {
        printf("queue is full\n");
        return 1;
    }
    else
    {
        printf("queue is not full\n");
        return 0;
    }
}

int is_empty(struct queue data)
{
    if(data.front == data.rear)
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

void enqueue(struct queue * p, int n)
{
    if(!is_full(*p))
    {
        p->rear++;
        p->Q[p->rear] = n;
    }

    display_queue(*p);
}

void dequeue(struct queue * p)
{
    if(!is_empty(*p))
    {
        p->front++;
        printf("%d\n", p->Q[p->front]);
    }
    display_queue(*p);
}

int main()
{
    int op, n;
    struct queue obj;

    obj.front = obj.rear = -1;
    printf("enter queue size needed:\n");
    scanf("%d", &obj.size);
    obj.Q = malloc((obj.size) * sizeof(int));
    if(obj.Q)
    {
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
                    enqueue(&obj, n);
                    break;
                
                case 2:
                    dequeue(&obj);
                    break;

                case 3:
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
        if(obj.Q)
            free(obj.Q);
    return 0;
}