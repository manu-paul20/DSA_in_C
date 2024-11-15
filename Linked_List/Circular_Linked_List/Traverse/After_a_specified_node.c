// Hey , if you found this code helpful , then follow me on github
// Dont be shocked after seeing the length of the program , its just formatted

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
  int searchData;
  printf("Enter the data of the no node after which you want to add a node : ");
  scanf("%d", &searchData);
  struct node *ptr = head;
  // Searching for specified node
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
  // searching node
  if (ptr->data != searchData)
  {
    printf("Node not found\n");
  }
  else
  {
    if (ptr->next == head)
    {
      printf("There is no node after the specified node\n");
    }
    else
    {
      ptr = ptr->next; // This line will just forward the specified node location by 1 step
                       // Because i have to print data after the specified node , not from the specified node
      while (ptr->next != head)
      {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
      }
      if (ptr->next == head)
      {
        printf("%d\n", ptr->data); // This will print the data of the last node
                                   // Because the loop will broke without printing it 😭
      }
    }
  }
}