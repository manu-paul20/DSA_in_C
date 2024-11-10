// In this program i implemented queue operations using doubly linked list
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
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(); // function to add element
void dequeue(); // function to remove element
void display(); // function to display front element
int main()
{
  while (1)
  {
    int ch;
    printf("Enter 1 to enqueue()\nEnter 2 to dequeue()\nEnter 3 to display()\nEnter choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
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
void enqueue()
{
  if (nodeCount == (SIZE - 1))
  {
    printf("Queue is full\n");
  }
  else
  {
    int data;
    printf("Enter data : ");
    scanf("%d", &data);
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (front == NULL && rear == NULL)
    {
      front = rear = new_node;
    }
    else
    {
      rear->next = new_node;
      new_node->prev = rear;
      rear = new_node;
    }
    printf("Node added\n");
    nodeCount++;
  }
}
void dequeue()
{
  if (front == NULL && rear == NULL)
  {
    printf("Queue is empty\n");
  }
  else if (front == rear)
  {
    front = rear = NULL;
    printf("Queue is empty now\n");
  }
  else
  {
    struct node *temp = front;
    front = front->next;
    front->prev = NULL;
    free(temp);
    nodeCount--;
    printf("Node deleted\n");
  }
}
void display()
{
  if (front == NULL && rear == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Front element is %d\n", front->data);
  }
}