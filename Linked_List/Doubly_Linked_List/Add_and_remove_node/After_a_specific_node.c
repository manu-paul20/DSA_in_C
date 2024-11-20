#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void traverse();
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

void add_node(int data){
    int searchData;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head==NULL){
        head=new_node;
        printf("Node added\n");
    }else{
        printf("Enter data of the node you want to find : ");
        scanf("%d",&searchData);
        struct node *ptr = head;
        while(ptr->next != NULL){
            if(ptr->data==searchData){
                break;
            }else{
                ptr = ptr->next;
            }
        }
        if(ptr->data!=searchData){
            printf("Node not found\n");
        }else{
            new_node->next = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
            printf("Node added\n");
        }
    }
}

void delete_node(){
     int searchData;
     if(head==NULL){
        printf("Linked list is empty\n");
     }else if(head->next == NULL){
        head=NULL;
        printf("Linked list is empty now\n");
     }else{
        printf("Enter data of the node you want to find : ");
        scanf("%d",&searchData);
        struct node *ptr = head;
        while(ptr->next != NULL){
            if(ptr->data==searchData){
                break;
            }else{
                ptr = ptr->next;
            }
        }
        if(ptr->data!=searchData){
            printf("Node not found\n");
        }else{
            struct node *temp = ptr->next;
            ptr->next = ptr->next->next;
            ptr->next->prev = ptr;
            free(temp);
            printf("Node deleted\n");
        }
     }

}
void traverse(){
    struct node *ptr = head;
    while(ptr->next!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    if(ptr->next==NULL){
        printf("%d\n",ptr->data);
    }
}