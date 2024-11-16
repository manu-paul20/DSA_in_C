#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail = NULL; // I have not added any head node because , it's not needed for insertion and deletion
                         // You can add an head node if you want to traverse the linked list
void add_node();
void delete_node();
int main()
{
    while (1)
    {
        int ch;
        printf("Enter 1 for add node\nEnter 2 for delete node\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add_node();
            break;
        case 2:
            delete_node();
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }
}
void add_node()
{
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if (tail == NULL)
    {
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    printf("Node added\n");
}
void delete_node()
{
    if (tail == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (tail->prev == NULL && tail->next == NULL)
    {
        tail = NULL;
        printf("Linked list is empty now\n");
    }
    else
    {
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        printf("Node deleted\n");
    }
}