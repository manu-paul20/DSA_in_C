// Hey , if you found this code helpful , then forgot to follow 

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
struct node *tail;
void add_node();
void delete_node();
int main()
{
    while (1)
    {
        int ch;
        printf("Enter 1 for add node\nEnter 2 for delete_node\nEnter choice : ");
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
            break;
        }
    }
}
void add_node()
{
    int nodeData, searchData;
    printf("Enter data : ");
    scanf("%d", &nodeData);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = nodeData;
    new_node->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = tail = new_node; // If the the node that is going to added is the first one
        head->next = head;      // i set head->next = head , because its the fist node
        printf("Node added\n");
    }
    else
    {
        printf("Enter the data of the no node after which you want to add a node : ");
        scanf("%d", &searchData);
        struct node *ptr = head;
        // This program will find the specified node
        while (ptr->next != head)
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
        // searching end here

        if (ptr->data != searchData)
        {
            printf("Node not found\n");
        }
        else
        {
            new_node->next = ptr->next; // If the node is found then this code will add it between two nodes
            ptr->next = new_node;
            printf("Node added\n");
        }
    }
}

void delete_node()
{
    int searchData;
    printf("Enter the data of the node after which you want to add a node : ");
    scanf("%d", &searchData);
    struct node *ptr = head;
    //this section will find the specified node
    while (ptr->next != head)
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
        if (ptr->next == head)
        {
            printf("There is o node after the specified node\n");
        }
        else
        {  // this section will delete the node if its' found
            struct node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp); 
        }
    }
}