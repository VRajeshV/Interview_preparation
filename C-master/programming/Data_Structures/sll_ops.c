#include<stdio.h>
#include<stdlib.h>
struct list{
	int data;
	struct list *next;
};

static struct list *head = NULL;

void DisplayList(void)
{
	struct list *tmp = head;
	printf("\n\n\n");

	while(tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n\n");
}

void ReverseList()
{
	struct list *prv, *tmp, *nxt;
	
	//tmp = head;
	if(head != NULL)
	{
		prv = head;
		nxt = head->next;
		head->next = NULL;

		while(nxt != NULL)
		{
			tmp = nxt->next;
			nxt->next = prv;
			prv = nxt;
			nxt = tmp;
		}
		head = prv;
		DisplayList();
	}
}

//Reverse_recursive
//supply head and NULL for below function initially
void ReverseList_rec(struct list * cur, struct list * prev)
{   
    if(cur)
    {
        struct list * nxt;

        nxt = cur->next;
        cur->next = prev;
        ReverseList_rec(nxt, cur);
    }
    else
        head = prev;
}

void InsertNode(int n)
{
	struct list *tmp = head;
	struct list *node;
	if(head == NULL)
	{
		head = (struct list *)malloc(sizeof(struct list));
		if(head != NULL)
		{
			head->data = n;
			head->next = NULL;
		}
		else
			perror("malloc:");
	}
	else
	{
		node = (struct list *)malloc(sizeof(struct list));
		while(tmp->next != NULL)
			tmp = tmp->next;
		node->data = n;
		node->next = NULL;
		tmp->next = node;
	}
	DisplayList();
}

void DeleteNode(int n)
{
	struct list *tmp = head;
	struct list *tmp1;
	if(tmp != NULL)
	{
		if(tmp->data == n)
		{
			head = head->next;
			free(tmp);
		}
		else
		{
			while(tmp->next != NULL)
			{
				if(tmp->next->data == n)
				{
					tmp1 = tmp->next;
					tmp->next = tmp->next->next;
					free(tmp1);
					break;
				}
				tmp = tmp->next;
			}
		}
	}
	DisplayList();
}

int main()
{
	int opt, node;
	while(1)
	{
		printf("supported operations:\n1.insert node\n2.delete node\n3.reverse list\n");
		printf("4.display list\n");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1: printf("enter the node to insert:\n");
				scanf("%d", &node);
				InsertNode(node);
				break;
			case 2: printf("enter the node to delete:\n");
                                scanf("%d", &node);
                                DeleteNode(node);
                                break;
			case 3:     //ReverseList();
                        ReverseList_rec(head, NULL);
                                break;
			case 4: DisplayList();
				break;
			default: printf("invalid option:\n");
		}
	}
	return 0;
}
