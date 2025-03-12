#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;
void push(int x){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = top;
    top = newNode; 
}

void pop(){
    if(top==NULL) return;
    node* temp = top;
    top = temp->next;
    free(temp);
}

int Top_element(){
    if(top==NULL){
        printf("The stack is empty.\n");
        return -1;
    }
    return top->data;
}

bool is_empty(){
    return top == NULL;
}
int main(){
    push(2);
    push(5);
    push(10);
    pop();
    push(12);
    printf("Top element is %d\n",Top_element());
    printf("Is stack empty? %s\n", is_empty() ? "YES" : "NO");
    return 0;
}