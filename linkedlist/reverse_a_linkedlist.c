#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head;
void insert(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    node* temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
}
void print(){
    node* temp = head;
    printf("The list is : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// reversing
void reverse(){
    node *prev, *current, *next;
    prev = NULL;
    current = head;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }
    head = prev;
}
int main(){
    head = NULL;
    insert(2); // list is 2
    insert(8); // list is 2 8
    insert(7); // list is 2 8 7
    insert(9); // list is 2 8 7 9
    insert(5); // list is 2 8 7 9 5
        print();
    reverse();
        print();
    return 0;
}