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
void reverse(node* p){
    if(p->next==NULL){
        head = p;
        return;
    }
    reverse(p->next);
    // node* q = p->next;
    // q->next = p;
    p->next->next = p;
    p->next = NULL;
}
int main(){
    head = NULL;
    insert(3);
    insert(5);
    insert(2);
    insert(9);
    insert(8);
    print();
    reverse(head);
    print();
    return 0;
}