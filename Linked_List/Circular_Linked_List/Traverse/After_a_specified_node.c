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
  //This section code is deleted due to some issue's
}