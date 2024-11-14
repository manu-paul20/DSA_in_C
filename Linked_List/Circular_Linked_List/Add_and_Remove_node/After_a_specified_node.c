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
  //This section code is deleted due to some issue's
}