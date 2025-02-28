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
// deletes node at position n
void delete(int p){
    node* temp = head;
    if(p==1){
        head = temp->next;
        free(temp);
        return;
    }
    node* temp1 = head;
    for(int i=0; i<p-2; i++){
        temp1 = temp1->next;
    }
    // temp1 points to (n-1)th Node
    temp = temp1->next; // nth node
    temp1->next = temp->next; // (n+1) node
    free(temp);
}
int main(){
    head = NULL;
    insert(2); // list is 2
    insert(8); // list is 2 8
    insert(7); // list is 2 8 7
    insert(9); // list is 2 8 7 9
    insert(5); // list is 2 8 7 9 5
        print();
    printf("Enter the position of the number you wanna delete : ");
    int n;
    scanf("%d",&n);
    delete(n);
        print();
    return 0;
}