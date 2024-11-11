// Today in this program i will traverse a linked list from beginning
// In this program we have a pre-defined linked list consist three nodes

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head = NULL;
void traverse();
int main()
{
  head = (struct node *)malloc(sizeof(struct node));
  head->next = (struct node *)malloc(sizeof(struct node));
  head->next->next = (struct node *)malloc(sizeof(struct node));
  head->data = 1;
  head->next->data = 2;
  head->next->next->data = 3;
  head->next->next->next = NULL;
  while (1)
  {
    int ch;
    printf("Enter 1 for start traversing\nEnter 2 for exit()\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      traverse();
      break;
    case 2:
      exit(0);
      break;
    default:
      printf("Invalid Input\n");
      break;
    }
  }
}

// Basic program for traversing
void traverse()
{
  struct node *ptr = head;
  while (ptr->next != NULL)
  {
    printf("%d\n", ptr->data);

    ptr = ptr->next;
  }
  if (ptr->next == NULL)
  {
    printf("%d\n", ptr->data);
  }
}