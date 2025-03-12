#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* tail;

void InsertBetNode(int data, int pos){
    // creating a new node
    node* newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    // Handle the empty list case
    if(tail==NULL){
        if(pos!=1){
            printf("Invalid position. List is empty, Only position 1 is valid.\n");
            free(newNode);
            return;
        }
        tail = newNode;
        newNode->next = tail; // circular reference
        return;
    }

    // Hnadle insertion at position 1;
    if(pos==1){
        newNode->next = tail->next;
        tail->next = newNode;
        return;
    }

    // Traverse to the (n-1)th node
    node* temp = tail->next;
    for(int i=1; i<pos-1; i++){
        temp = temp->next;
        if(temp==tail->next){ //check if position is out of bounds
            printf("Invalid position, out of bounds.\n");
            free(newNode);
            return;
        }
    }

    //Inser the new node
    newNode->next = temp->next;
    temp->next = newNode;

    //update tail if inserting at the end
    if(temp==tail){
        tail=newNode;
    }
}

void print(){
    if(tail==NULL){
        printf("The list is empty.\n");
        return;
    }

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
    int n,pos,data;
    printf("how many nodes?: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("Enter the data with its position : ");
        scanf("%d %d",&data,&pos);
        InsertBetNode(data, pos);
        print();
    }
    // Free the list
    if(tail!=NULL){
        node* current = tail->next;
        node* nextNode;
        do{
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != tail->next);
    }
    return 0;
}