#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
void add_node(int val);
void remove_node();
int main()
{
  while (1)
  {
    int ch, val;
    printf("1 for add\n2 for delete\n3 for exit()\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter data : ");
      scanf("%d", &val);
      add_node(val);
      break;
    case 2:
      remove_node();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Invalid input\n");
      break;
    };
  }
  return 0;
}
void add_node(int val)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->next = NULL;
  if (head == NULL)
  {
    head = new_node;
  }
  else
  {
    new_node->next = head;
    head = new_node;
  }
  printf("Value added\n");
}
void remove_node()
{
  struct node *temp = head;
  if (head == NULL)
  {
    printf("Linked list is empty\n");
  }
  else if (head->next == NULL)
  {
    head = NULL;
    printf("Linked list is empty now\n");
  }
  else
  {
    head = head->next;
    free(temp);
    printf("Node deleted\n");
  }
}
