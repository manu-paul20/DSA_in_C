// Hey , if you found this code helpful , then follow me on github

#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *head;
struct node *tail;
void traverse();
int main()
{
  head = (struct node *)malloc(sizeof(struct node));
  head->next = (struct node *)malloc(sizeof(struct node));
  tail = (struct node *)malloc(sizeof(struct node));
  head->next->next = tail;
  tail->next = head;
  head->data = 1;
  head->next->data = 2;
  tail->data = 3;
  while (1)
  {
    int ch;
    printf("Enter 1 for start traversing\nEnter 2 for exit\nEnter choice : ");
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
void traverse()
{
  int data;
  printf("Enter after which node you want to start traversing : ");
  scanf("%d", &data);
  struct node *ptr = head;
  // started finding the specified node
  while (ptr->next != head)
  {
    if (ptr->data == data)
    {
      break; // If any node's data matches with the specified data then the loop will break
    }
    else
    {
      ptr = ptr->next; // Else it will automatically broke in last node
    }
  }
  // searching end

  // searching results
  if (ptr->next == head && ptr->data != data)
  {
    printf("Specified node not found\n");
  }
  else
  {
    if (ptr->next == head)
    {
      printf("There is no node after the specified node\n");
    }
    else
    {
      // This section will print all data after specified node , not from the specified node
      ptr = ptr->next;
      while (ptr->next != head)
      {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
      }
      if (ptr->next == head)
      {
        printf("%d\n", ptr->data);
      }
    }
  }
}