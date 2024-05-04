/* 
 * C program to Implement the Doubly Linked List and its Operations
 */
 
#include<stdio.h>
#include<stdlib.h>
 
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
 
struct node* head = NULL;
 
/* functions prototyping */
void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_position(int, int);
void delete_from_beginning();
void delete_from_position(int);
void delete_from_end();
void print_from_beginning();
void print_from_end(struct node*);
void search_data(int);
void update_node_data(int, int);
void list_sort();
 
/* helper functions */
struct node* create_node(int);
int size_of_list();
int getData();
int getPosition();
void empty_list_message();
void memory_error_message();
void invalid_position_message();
 
int main()
{
    char user_active = 'Y';
    int user_choice;
    int data, position;
 
    while (user_active == 'Y' || user_active == 'y')
    {
 
        printf("\n\n------ Doubly Linked List -------\n");
        printf("\n1. Insert a node at the beginning");
        printf("\n2. Insert a node at the end");
        printf("\n3. Insert a node at the given position");
        printf("\n\n4. Delete a node from the beginning");
        printf("\n5. Delete a node from the end");
        printf("\n6. Delete a node from the given position");
        printf("\n\n7. Print list from the beginning");
        printf("\n8. Print list from the end");
        printf("\n9. Search a node data");
        printf("\n10. Update a node data");
        printf("\n11. Sort the list");
        printf("\n12. Exit");
        printf("\n\n------------------------------\n");
 
        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);
 
        printf("\n------------------------------\n");
        switch(user_choice)
        {
            case 1:
                printf("\nInserting a node at beginning");
                data = getData();
                insert_at_beginning(data);
                break;
 
            case 2:
                printf("\nInserting a node at end");
                data = getData();
                insert_at_end(data);
                break;
 
            case 3: 
                printf("\nInserting a node at the given position");
                data = getData();
                position = getPosition();
                insert_at_position(data, position);
                break;
 
            case 4: 
                printf("\nDeleting a node from beginning\n");
                delete_from_beginning();
                break;
 
            case 5: 
                printf("\nDeleting a node from end\n");
                delete_from_end();
                break;
 
            case 6: 
                printf("\nDelete a node from given position\n");
                position = getPosition();
                delete_from_position(position);
                break;
 
            case 7: 
                printf("\nPrinting the list from beginning\n\n");
                print_from_beginning();
                break;
 
            case 8: 
                printf("\nPrinting the list from end\n\n");
                print_from_end(head);
                printf("NULL\n");
                break;
 
            case 9:
                printf("\nSearching the node data");
                data = getData();
                search_data(data);
                break;
 
            case 10:
                printf("\nUpdating the node data");
                data = getData();
                position = getPosition();
                update_node_data(data, position);
                break;
 
            case 11:
                printf("\nSorting the list\n");
                list_sort();
                break;
 
            case 12:
                printf("\nProgram was terminated\n\n");
                return 0;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
 
    return 0;    
}
 
/* prints the message when the memory was not allocated */
void memory_error_message() 
{
    printf("\nMemory was not allocated!\n");
}
 
/* prints the message when the position is not valid for operation*/
void invalid_position_message()
{
    printf("\nInvalid position!\n");
}
 
/* prints the message when the linked list is empty */
void empty_list_message()
{
    printf("\nList is Empty!\n");
}
 
/* creates a new node dynamically */
struct node* create_node(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    if (new_node == NULL)
    {
        return NULL;
    }
    else
    {
        new_node->prev = NULL;
        new_node->data = data;
        new_node->next = NULL;
    }
}
 
/* inserts a new node at beginning of the list */
void insert_at_beginning(int data)
{
    struct node* new_node = create_node(data);
 
    if (new_node == NULL)
    {
        memory_error_message();
        return;
    }
    else if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
/* inserts a new node at the end of the list */
void insert_at_end(int data)
{
    struct node* new_node = create_node(data);
 
    if (new_node == NULL)
    {
        memory_error_message();
        return;
    }
    else if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node* temp = head;
        //traverse to the last node
        while (temp->next != NULL)
        {
            temp = temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
/* inserts a new node at the given position */
void insert_at_position(int data, int pos)
{
    struct node* new_node = create_node(data);
    int size = size_of_list();
 
    if (new_node == NULL)
    {
        memory_error_message();  
        return;
    }
    else if (head != NULL && (pos < 1 || pos > size))
    {
        invalid_position_message();
        return;
    }
    else if (head == NULL && pos == 1)
    {
        head = new_node;
    }
    else if (head != NULL && pos == 1)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else
    {
 
        struct node* temp = head;
        int count = 1;
 
        //traverse to the before given position
        while (++count < pos)
        {
            temp = temp->next;
        }
 
        temp->next->prev = new_node;
        new_node->next = temp->next;
 
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("\n* Node with data %d was inserted \n", data);
}
 
/* deletes a node from the beginning of the list */
void delete_from_beginning()
{
    if (head == NULL)
    {
        empty_list_message();
        return;
    }
    struct node* temp = head;
    head = head->next;
    int data = temp->data;
 
    //free the memory from the heap
    free(temp);
 
    printf("\n* Node with data %d was deleted \n", data);
}
 
/* deletes a node from the end of the list */
void delete_from_end()
{
 
    if (head == NULL)
    {
        empty_list_message();
        return;
    }
    struct node* temp = head;
    int data = 0;
 
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
 
    if (temp->prev == NULL)
    {
        head = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
    }
    data = temp->data;
 
    free(temp);
    printf("\n* Node with data %d was deleted \n", data);
}
 
/* deletes a node from the given position */
void delete_from_position(int pos)
{
 
    if (head == NULL)
    {
        empty_list_message();
        return;
    }
    int size = size_of_list();
    struct node* temp = head;
    int data = 0;
 
    if (pos < 1 || pos > size)
    {
        invalid_position_message();
        return;
    }
    else if (pos == 1)
    {
        head = head->next;
        data = head->data;
        free(temp);
        printf("\n* Node with data %d was deleted \n", data);
    }
    else
    {
        int count = 0;
 
        while (++count < pos)
        {
            temp = temp->next;
        }
 
        //update previous node
        temp->prev->next = temp->next;
 
        // if deleting the last node then just update the previous node
        if (pos != size)
        {
            //update next node
            temp->next->prev = temp->prev;
        }
        data = temp->data;
 
        //free memory
        free(temp);
 
        printf("\n* Node with data %d was deleted \n", data);
    }
}
 
/* prints the data of nodes from the beginning of the list */
void print_from_beginning()
{
    struct node* temp = head;
 
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
 
/* prints the data of nodes from the end of the list */
void print_from_end(struct node* head)
{
    if (head == NULL)
    {
        return;
    }
 
    print_from_end(head->next);
    printf("%d  ", head->data);
}
 
/* search a data node with the given value */
void search_data(int data)
{
    struct node* temp = head;
    int position = 0;
    int flag = 0;
 
    while (temp != NULL)
    {
        position += 1;
        if (temp->data == data)
        {
            flag = 1;
            break;        
        }
        temp = temp->next;
    }
 
    if (flag == 0)
    {
        printf("\nNode with data %d was not found\n", data);
    }
    else
    {
        printf("\nNode found at %d position\n", position);
    }
}
 
/* updates a node from the given position */
void update_node_data(int data, int pos)
{
    if (head == NULL)
    {
        empty_list_message();
        return;
    }
 
    int size = size_of_list();
 
    if (pos < 1 || pos > size)
    {
        invalid_position_message();
        return;
    }
 
    struct node* temp = head;
    int count  = 1;
 
    while (++count < pos)
    {
        temp = temp->next;
    }
 
    temp->data = data;
 
    printf("\nNode Number %d was Updated!\n", pos);
}
 
/* sort the linked list data using insertion sort */
void list_sort()
{
    if (head == NULL)
    {
       empty_list_message();
       return;
    }
    struct node* temp1 = head;
    struct node* temp2 = head;
    int key = 0;
 
    while (temp1 != NULL)
    {
        key = temp1->data;
        temp2 = temp1;
 
        while (temp2->prev != NULL && temp2->prev->data > key)
        {
            temp2->data = temp2->prev->data;
            temp2 = temp2->prev;
        }
        temp2->data = key;
        temp1 = temp1->next;
    }
 
    printf("\nList was sorted!\n");
}
 
/* getting node data from the user */
int getData()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);
 
    return data;
}
 
/* getting node position from the user */
int getPosition()
{
    int position;
    printf("\nEnter Position: ");
    scanf("%d", &position);
 
    return position;
}
 
/* finding the size of the list */
int size_of_list()
{
    struct node* temp = head;
    int count = 0;
 
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;    
    }
 
    return count;
}