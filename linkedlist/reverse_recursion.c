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
void print(node* head){
    if(head==NULL){
        printf("\n");
        return;
    }
    printf("%d ",head->data);
    print(head->next);
}
void reverseprint(node* head){
    if(head==NULL){
        return;
    }
    reverseprint(head->next);
    printf("%d ",head->data);
}
int main(){
    head = NULL;
    insert(2); // list is 2
    insert(8); // list is 2 8
    insert(7); // list is 2 8 7
    insert(9); // list is 2 8 7 9
    insert(5); // list is 2 8 7 9 5
    printf("The list is : ");
    print(head);
    printf("The reversed list is : ");
    reverseprint(head);
    return 0;
}