// In this program we will implement Stack operations using array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int stack[SIZE], top = -1;
void push(int x);  // function to add element at the top of the stack
void pop(); //function to remove top element of the stack
void peek(); //function to display top element of the stack
int isFull(); // function to check if the stack is full or not
int isEmpty(); // function to check is the stack is empty or not
void main()
{
    while (1)
    {
        int choice, val;
        printf("Enter 1 for Push()\nEnter 2 for Pop()\nEnter 3 for Peek()\nEnter 4 for close the program\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull())
            {
                printf("Enter element : ");
                scanf("%d", &val);
                push(val);
            }
            else
            {
                printf("Stack is full\n");
            }
            break;
        case 2:
            if (isEmpty())
            {
                pop();
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 3:

            if (isEmpty())
            {
                peek();
            }
            else
            {
                printf("Stack is empty\n");
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
    if (top == SIZE - 1)
    {
        return 0; // indicates stack is full and overflow condition appears
    }
    else
    {
        return 1; // indicates stack is not full
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 0; // indicates stack is Empty and underflow condition appears
    }
    else
    {
        return 1; // indicates stack is not empty
    }
}

void push(int x)
{
    stack[++top] = x;
    printf("Value Entered\n");
}

void pop()
{
    top--;
    printf("Top element removed from the stack\n");
}

void peek()
{
    printf("Top element is %d\n", stack[top]);
}