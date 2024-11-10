// In this program i implemented a stack using a doubly linked list
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
int nodeCount = -1;
struct node *ground = NULL;
struct node *top = NULL;
void push();    // function to add element
void pop();     // function to delete element
void display(); // function to display top element
int main()
{
  while (1)
  {
    int ch;
    printf("Enter 1 to push()\nEnter 2 to pop()\nEnter 3 to display()\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      push();
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    default:
      printf("Invalid choice\n");
      break;
    }
  }
}
void push()
{
  int data;
  if (nodeCount == (SIZE - 1))
  {
    printf("Stack is full\n");
  }
  else
  {
    printf("Enter data : ");
    scanf("%d", &data);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (ground == NULL && top == NULL)
    {
      ground = top = new_node;
    }
    else
    {
      top->next = new_node;
      new_node->prev = top;
      top = new_node;
    }
    printf("Node added\n");
    nodeCount++;
  }
}
void pop()
{
  if (ground == NULL && top == NULL)
  {
    printf("Stack is empty\n");
  }
  else if (ground == top)
  {
    ground = top = NULL;
    printf("Stack is empty now\n");
  }
  else
  {
    struct node *temp = top;
    top = top->prev;
    top->next = NULL;
    free(temp);
    nodeCount--;
    printf("Node deleted\n");
  }
}
void display()
{
  if (ground == NULL && top == NULL)
  {
    printf("Stack is empty\n");
  }
  else
  {
    printf("Top element is %d\n", top->data);
  }
}