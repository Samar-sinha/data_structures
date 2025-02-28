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
    temp->next = head;
    head = temp;
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
    // insert(2); // list is 2
    // insert(8); // list is 8 2
    // insert(7); // list is 7 8 2
    // insert(9); // list is 9 7 8 2
    // insert(5); // list is 5 9 7 8 2
    //    print();
    int n,x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        printf("Enter the number: ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    return 0;
}