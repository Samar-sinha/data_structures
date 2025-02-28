#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* insert(node* head, int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        return head;
    }
    node* temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return head;
}
void print(node* head){
    node* temp = head;
    printf("The list is : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// reversing
node* reverse(node* head){
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
    return head;
}
int main(){
    node* head = NULL;
    head = insert(head, 2); // list is 2
    head = insert(head, 8); // list is 2 8
    head = insert(head, 7); // list is 2 8 7
    head = insert(head, 9); // list is 2 8 7 9
    head = insert(head, 5); // list is 2 8 7 9 5
        print(head);
    head = reverse(head);
        print(head);
    return 0;
}