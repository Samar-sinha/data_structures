#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* tail;
void InsertingAtEnd(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    if(tail==NULL){
        tail = newNode;
        newNode->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}
void print(){
    node* temp = tail->next;
    printf("The list is: ");
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=tail->next);
    printf("\n");
}
int main(){
    tail = NULL;
    InsertingAtEnd(5); print();
    InsertingAtEnd(10); print();
    InsertingAtEnd(8); print();
    InsertingAtEnd(69); print();
    return 0;
}