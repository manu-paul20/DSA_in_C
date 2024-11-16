#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
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
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    printf("Node added\n");
}
void delete_node()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else if (head->prev == NULL && head->next == NULL)
    {
        head = NULL;
        printf("Linked list is empty now\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("Node deleted\n");
    }
}