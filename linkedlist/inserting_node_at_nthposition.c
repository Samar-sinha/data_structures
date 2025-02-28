#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head;
void insert(int n, int p){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = n;
    temp->next = NULL;
    if(p==1){
        temp->next = head;
        head = temp;
        return;
    }
    node* temp1 = head;
    for(int i=0; i<p-2; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
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
int main(){
    head = NULL;
    insert(2, 1); // list is 2
    insert(8, 2); // list is 2 8
    insert(7, 1); // list is 7 2 8
    insert(9, 3); // list is 7 2 9 8
    insert(5, 2); // list is 7 5 2 9 8
        print();
    return 0;
}