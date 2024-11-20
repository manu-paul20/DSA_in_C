#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void add_node(int data);
void delete_node();
int main(){
    int ch,data;
    while(1){
    printf("Enter 1 for add node\nEnter 2 for delete node\nEnter your choice : ");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("Enter data : ");
        scanf("%d",&data);
        add_node(data);
        traverse();
        break;
    case 2:
       delete_node();
       traverse();
       break;
    default:
    printf("Invalid input\n");
        break;
    }
    }
}

// All functions are deleted due to some issues .  They will be added soon