// Doubly Linked List implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
node* head; // global variable - pointer to head node
node* GetNewnode(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void InsertAtHead(int x){
    node* newNode = GetNewnode(x);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;   
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(int x){
    node* newNode = GetNewnode(x);
    node* temp = head; // Traversing to the last node.
    if(head==NULL){
        head = newNode;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void print(){
    node* temp = head;
    printf("Forward: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverseprint(){
    node* temp = head;
    if(temp==NULL)  return; //empty list, exit
    // going to the last Node
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("reverse: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
int main(){
    head = NULL; //empty list
    InsertAtHead(2); print(); reverseprint();
    InsertAtHead(9); print(); reverseprint();
    InsertAtHead(4); print(); reverseprint();
    InsertAtTail(15); print(); reverseprint();
    InsertAtTail(7); print(); reverseprint();
    return 0;
}
