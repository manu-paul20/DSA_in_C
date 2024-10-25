//In this program we will implement Queue operations using array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], front = -1, rear = -1;
void enqueue(int x); // function to add element at the rear of the Queue
void dequeue();      // function to remove front element of the Queue
void peek();         // function to display front element of the Queue
int isFull();        // function to check if the Queue is full or not
int isEmpty();       // function to check is the Queue is empty or not
void main()
{
    while (1)
    {
        int choice, val;
        printf("Enter 1 for Enqueue()\nEnter 2 for Dequeue()\nEnter 3 for Peek()\nEnter 4 for close the program\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Enter element : ");
                scanf("%d", &val);
                enqueue(val);
                if (front == -1)
                {
                    front++;
                }
            }
            else
            {
                printf("Queue is full\n");
            }
            break;
        case 2:
            if (isEmpty())
            {
                dequeue();
            }
            else
            {
                printf("Queue is empty\n");
            }
            break;
        case 3:

            if (isEmpty())
            {
                peek();
            }
            else
            {
                printf("Queue is empty\n");
            }
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Invalid Input\n");
            break;
        }
    }
}

int isFull()
{
    if (rear == SIZE - 1)
    {
        return 0; // Indicates Queue is full
    }
    else
    {
        return 1; // Indicates Queue is not full
    }
}

int isEmpty()
{
    if (front == -1)
    {
        return 0; // Indicates Queue is empty
    }
    else
    {
        return 1; // Indicates Queue is not empty
    }
}

void enqueue(int x)
{
    queue[++rear] = x;
    printf("Value Entered\n");
}

void dequeue()
{
    front++;
    printf("Front element deleted\n");
    if (front > rear) // <-- This If statement Makes the queue empty if front becomes greater than rear
    {
        front = -1;
        rear = -1;
        printf("Queue is now empty\n");
    }
}

void peek()
{
    printf("Front element is %d\n", queue[front]);
}