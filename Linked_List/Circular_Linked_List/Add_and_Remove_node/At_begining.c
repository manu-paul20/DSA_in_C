// Author - Manu Paul
// Created at - 11 NOV 2024

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
    head = tail = new_node;
  }
  else
  {
    new_node->next = head;
    head = new_node;
    tail->next = head;
  }
  printf("Value added\n");
}
void remove_node()
{
  if (head == NULL && tail == NULL)
  {
    printf("Linked list is empty\n");
  }
  else if (head == tail)
  {
    head = tail = NULL;
    printf("Linked list is empty now\n");
  }
  else
  {
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted\n");
    if (head == tail)
    {
      tail->next = NULL;
    }
    else
    {
      tail->next = head;
    }
  }
}
