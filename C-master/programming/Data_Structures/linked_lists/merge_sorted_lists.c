#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

void swap_data(struct node * node1, struct node * node2)
{
    int tmp = node1->data;
    node1->data = node2->data;
    node2->data = tmp;
}

void display_list(struct node * list)
{
    struct node * tmp = list;

    while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
void sort_list(struct node * head)
{
    struct node * tmp, * tmp1;

    tmp = head;

    while(tmp->next)
    {
        tmp1 = tmp->next;
        while(tmp1->next)
        {
            if((tmp->data) > (tmp1->data))
                swap_data(tmp, tmp1);
            tmp1 = tmp1->next;
        }
        if((tmp->data) > (tmp1->data))
                swap_data(tmp, tmp1);
        tmp = tmp->next;
    }
}
//assuming input lists are sorted so that resulted list will be sorted
void merge_lists(struct node ** result, struct node * head1, struct node * head2)
{
    struct node * tmp = NULL;

    while(head1 && head2)
    {
        if((head1->data) > (head2->data))
        {
            if(tmp)
            {
                tmp->next = head2;
                tmp = tmp->next;
            }
            else
            {
                *result = head2;
                tmp = *result;
            }

            head2 = head2->next;
        }
        else
        {
            if(tmp)
            {
                tmp->next = head1;
                tmp = tmp->next;
            }
            else
            {
                *result = head1;
                tmp = *result;
            }

            head1 = head1->next;
        }
    }
    if(head1)
        tmp->next = head1;
    else if(head2)
        tmp->next = head2;
}

void insert_node(struct node ** head, int n)
{
    struct node * Node = malloc(sizeof(struct node));
    struct node * tmp = * head;

    if(Node)
    {
        Node->data = n;
        Node->next = NULL;
        if(tmp)
        {
            while(tmp->next)
                tmp = tmp->next;
            tmp->next = Node;
        }
        else
            *head = Node;
    }
    else
        perror("malloc for Node:");
}

int main()
{
    int n, i, ele;
    struct node * head1 = NULL, * head2 = NULL, * mlist = NULL;

    printf("entern number of nodes for list1:\n");
    scanf("%d", &n);
    printf("enter elements for list1\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &ele);
        insert_node(&head1, ele);
    }

    printf("entern number of nodes for list2:\n");
    scanf("%d", &n);
    printf("enter elements for list2\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &ele);
        insert_node(&head2, ele);
    }
    printf("input lists...\n");
    display_list(head1);
    display_list(head2);
    sort_list(head1);
    sort_list(head2);
    printf("after sorting...\n");
    display_list(head1);
    display_list(head2);
    merge_lists(&mlist, head1, head2);
    printf("after merging...\n");
    display_list(mlist);
}