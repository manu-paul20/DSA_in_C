#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void add_node(int val);
void delete_node();
int main()
{
  while (1)
  {
    int ch, val;
    printf("Enter 1 for add node at end\nEnter 2 for remove node from end\nEnter 3 for close the program\nEnter your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter Data of the node : ");
      scanf("%d", &val);
      add_node(val);
      break;
    case 2:
      delete_node();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Invalid input\n");
      break;
    }
  }
  return 0;
}
void add_node(int val)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->next = head;
  if (head == NULL && tail == NULL)
  {
    head = tail = new_node;
  }
  else
  {
    tail->next = new_node;
    tail = new_node;
  }
  printf("Node added\n");
}
void delete_node()
{
  struct node *temp;
  if (head == NULL && tail == NULL)
  {
    printf("Linked list is empty\n");
  }
  else if (tail == head)
  {
    head = tail = NULL;
    printf("Linked list is empty now\n");
  }
  else
  {
    temp = head;
    while (temp->next->next != head)
    {
      temp = temp->next;
    }
    free(tail);
    tail = temp;
    tail->next = head;
    printf("Node deleted\n");
  }
}