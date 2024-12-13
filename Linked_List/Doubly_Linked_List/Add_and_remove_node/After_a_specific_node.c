#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a specific node
void insertAfter(struct Node **head, int target, int data) {
    struct Node *current = *head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    printf("Node with data %d inserted after node with data %d.\n", data, target);
}

// Function to delete a node after a specific node
void deleteAfter(struct Node **head, int target) {
    struct Node *current = *head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }

    if (current->next == NULL) {
        printf("No node exists after node with data %d to delete.\n", target);
        return;
    }

    struct Node *toDelete = current->next;
    current->next = toDelete->next;

    if (toDelete->next != NULL) {
        toDelete->next->prev = current;
    }

    free(toDelete);
    printf("Node after node with data %d deleted.\n", target);
}

// Function to display the doubly linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Create an initial list: 10 <-> 20 <-> 30
    head = createNode(10);
    struct Node *second = createNode(20);
    struct Node *third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    displayList(head);

    // Insert a node with data 25 after node with data 20
    insertAfter(&head, 20, 25);
    displayList(head);

    // Delete the node after node with data 20
    deleteAfter(&head, 20);
    displayList(head);

    return 0;
}
