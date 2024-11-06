#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void addNode(int val);
void deleteNode();
int main()
{
    while (1)
    {
        int ch, val, searchData;
        printf("Enter 1 for add\nEnter 2 for delete\nEnter 3 for exit()\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data of node which you want to create : ");
            scanf("%d", &val);
            addNode(val);
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}
void addNode(int val)
{
    int searchData;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        printf("Enter data of the node after which you want to create a node : ");
        scanf("%d", &searchData);
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == searchData)
            {
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        if (ptr->data != searchData)
        {
            printf("Node not found\n");
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
            printf("Node Added\n");
        }
    }
}
void deleteNode()
{
    int searchData;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        printf("Enter data of the node after which you want to delete a node : ");
        scanf("%d", &searchData);
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == searchData)
            {
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        if (ptr->data != searchData)
        {
            printf("Node not found\n");
        }
        else if (ptr->next == NULL)
        {
            printf("No node found this node\n");
        }
        else
        {
            struct node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            printf("Node deleted\n");
        }
    }
}
