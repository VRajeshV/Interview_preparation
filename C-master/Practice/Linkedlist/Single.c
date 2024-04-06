#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int num;
    struct Node *ptr;
};

void print(struct Node *list)
{
    struct Node* tmp;
    tmp = list;
    printf("List\n");
    while(tmp)
    {
        printf(" %d -> ",tmp->num);
        tmp = tmp->ptr;
    }
    printf("\n");
}

void insert_end(struct Node **head,int data)
{
    struct Node *tmp = *head;

    struct Node* Node = (struct Node*) malloc(sizeof(struct Node));

    if(Node)
    {
        Node->num = data;
        Node->ptr = NULL;

        if(tmp)
        {
            while(tmp->ptr)
                tmp = tmp->ptr;
            tmp->ptr = Node;

        }
        else
        {
            *head = Node; 
        }
    }
}

void insertstart(struct Node** head, int data)
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node*));

    newnode->num = data;
    newnode->ptr = *head;

    *head = newnode;
}

void deleteNode(struct Node **head, int position)
{
    struct Node* temp;
    struct Node* prev;

    temp = *head;
    prev = *head;

    for(int i=0 ;i < position; i++)
    {
        if(i==0 && position == 1 )
        {
            *head = (*head)->ptr;
            free(temp);
        }
        else
        {
            if(i == position - 1 && temp)
            {
                prev->ptr = temp->ptr;
                free(temp);
            }
            else
            {
                prev = temp;

                if(prev == NULL)
                {
                    break;
                }
                temp = temp->ptr;
            }
        }
     }
}

int main()
{
    struct Node *list = NULL;
    int size,data;
    printf("enter number of nodes in list \n");
    scanf("%d",&size);
    printf("enter data");
    for(int i=1 ; i<=size;i++)
    {
        scanf("%d",&data);
        insertstart(&list,data);
    }

    print(list);
    
}