#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
node* head;

void InsertAtBeg(int x){
    node* NewNode = (node*)malloc(sizeof(node));
    NewNode->data = x;
    NewNode->next = head;
    head = NewNode;
}

void print(){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(node** top, node* node){
    node->next = *top;
    *top = node;
}
node* pop(node** top){
    if(*top==NULL){
        return NULL;
    }
    node* temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    return temp; 
}
void ReverseLinkedlist(){
    if(head == NULL || head->next == NULL) return; //No need to reverse if the list is empty or has only one node.
    node* stackTop = NULL;
    node* current = head;
    // push all the nodes onto the stack.
    while(current!=NULL){
        node* NextNode = current->next;
        push(&stackTop, current);
        current = NextNode;
    }
    // pop all nodes from the stack to reverse the list
    head = pop(&stackTop);
    current = head;
    while(stackTop!=NULL){
        current->next = pop(&stackTop);
        current = current->next;
    }
    current->next = NULL; // set the last node's next to NULL.
}
int main(){
    head = NULL;
    InsertAtBeg(4);
    InsertAtBeg(7);
    InsertAtBeg(9);
    InsertAtBeg(14);
    InsertAtBeg(1);
    
    printf("The list is: ");
    print();
    
    ReverseLinkedlist();

    printf("Reversed Linked list: ");
    print();
    return 0;
}