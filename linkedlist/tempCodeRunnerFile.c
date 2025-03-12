#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* tail;

void insert(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    if(tail==NULL){
        tail = newNode;
        newNode->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
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

void delete(int del){
    node* temp = tail->next;
    if(del==1){
        temp = tail->next;
        tail->next = temp->next;
        free(temp);
        return;
    }
    for(int i=0; i<del-2; i++){
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    if(tail==NULL) tail = temp;
}
int main(){
    tail = NULL;
    insert(4);
    insert(9);
    insert(2);
    insert(7);
    print();
    int del;
    printf("Enter the position that you wanna delete: ");
    scanf("%d",&del);
    delete(del);
    print();
    return 0;
}