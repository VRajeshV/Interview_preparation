#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};


void print(struct Node *head)
{
    struct Node *tmp = head;
    
    while(tmp)
    {
        printf(" %d -> ", tmp->data);
        tmp = tmp->link;
    }
}
void insertstart(struct Node **head,int data)
{
   
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
   
    node->data = data;
    node->link = *head;
  
    *head= node;
   
}

void insertend(struct Node **head,int data)
{
    struct Node *tmp = *head;
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;
    node->link = NULL;

    while(tmp->link)
    {
        tmp = tmp->link;
    }
    tmp->link= node;
}

void insertposition(struct Node **head,int position, int data)
{
    struct Node *tmp = *head;
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *prev;
    node->data = data;

    for(int i=1;i<= position;i++)
    {
        if(i==1 && i == position)
        {
            
            node->link = *head;
        
            *head= node;
            break;
        }
        else
        {    
            if(i == position)
            {
                node->link = tmp;
                prev->link = node;
            }
            else
            {
                prev = tmp;
                tmp = tmp->link;
            }
        }
    }
}

void delete(struct Node **head,int position)
{
    struct Node *tmp = *head;
    struct Node *node = (struct Node*)malloc(sizeof(struct Node*));

    struct Node *prev;

    for(int i=1;i<=position;i++)
    {
        if(i==1 && i==position)
        {
            *head = (*head)->link;
            free(tmp);
        }
        else
        {
            if(i == position)
            {
                prev->link = tmp->link;
                free(tmp);
            }
            else
            {
                prev = tmp;
                tmp = tmp->link;
            }
        }
    }

}

void main()
{
    struct Node *head=NULL;

    insertstart(&head,30);
    insertstart(&head,20);
    insertstart(&head,10);
    insertend(&head,40);
    insertposition(&head,4,50);
    printf("print LIST\n");
    print(head);
    printf("\n");
    delete(&head,4);
    printf("delete LIST\n");
    print(head);
    printf("\n");
}