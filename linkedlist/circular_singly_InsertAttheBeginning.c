#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* tail;
void InsertAtBeginning(int x){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    if(tail==NULL){
        tail = newnode;
        newnode->next = tail;
        return;
    }
    newnode->next = tail->next;
    tail->next = newnode;
}
void print(){
    if(tail==NULL){
        printf("The list is empty");
        return;
    }
    node* temp = tail->next;
    printf("The list is : ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }
    while(temp!=tail->next);
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