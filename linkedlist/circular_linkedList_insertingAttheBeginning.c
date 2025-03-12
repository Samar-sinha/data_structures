#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;
node* tail;
void InsertAtBeginning(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    if(tail==NULL){ // empty list.
        tail = newNode;
        newNode->next = tail;
        newNode->prev = tail;
        return;
    }
    // Inserting at the beginning when the list isn't empty.
    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next->prev = newNode;
    tail->next = newNode;
}
void print(){
    if(tail==NULL){ // check for the empty list
        printf("List is empty.\n");
        return;
    }
    node* temp = tail->next;
    printf("Forward: ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    } while(temp!=tail->next);
    printf("\n");
}

int main(){
    tail = NULL;
    InsertAtBeginning(5); print();
    InsertAtBeginning(7); print();
    InsertAtBeginning(15); print();
    InsertAtBeginning(1); print();
    return 0;
}