// Array-based implementation
#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE-1){
        printf("error: stack overflow\n");
        return;
    }
    // top++;
    // A[top] = x;
    A[++top] = x; // or simply we can write like this.
}

void pop(){
    if(top == -1){
        printf("Error: stack underflow\n");
        return;
    }
    top--;
}

int Top_element(){
    if(top == -1){
        printf("Error: stack is empty\n");
        return -1; // return an error value
    }
    return A[top];
}

void print(){
    printf("stack: ");
    for(int i=0; i<=top; i++) 
        printf("%d ",A[i]);
    printf("\n");
}
int main(){
    push(2);print();
    push(5);print();
    push(10);print();
    pop();print();
    push(12);print();
    printf("Top element is %d\n",Top_element());
}