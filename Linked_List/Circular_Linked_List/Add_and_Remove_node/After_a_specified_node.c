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
int main()
{
  while (1)
  {
    int ch;
    printf("Enter 1 for add node\nEnter 2 for exit()\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      add_node();
      break;
    case 2:
      exit(0);
      break;
    default:
      break;
    }
  }
}
void add_node()
{
  int searchData, nodeData;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d", &nodeData);
  new_node->data = nodeData;
  new_node->next = NULL;
  if (head == NULL&&tail==NULL)
  {
    head = tail = new_node;
    printf("Node added\n");
  }
  else
  {
    struct node *ptr = head;
    printf("Enter the data of the node after which you want to add a node : ");
    scanf("%d", &searchData);
    while (ptr->next != head)
    {
      if (ptr->data == searchData)
      {
        break; // it will break the loop if we find the specified data
      }
      else
      {
        ptr = ptr->next;
      }
    }
    if (ptr->next == head && ptr->data != searchData)
    {
      printf("Specified node not found\n");
    }
    else
    {
      tail->next = new_node;
      new_node->next = head;
      tail = new_node;
      printf("Node added\n");
    }
  }
}