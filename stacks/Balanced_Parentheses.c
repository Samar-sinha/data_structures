#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX 51
bool arePair(char opening, char closing){
    if( opening == '(' && closing == ')' ) return true;
    else if( opening == '{' && closing == '}' ) return true;
    else if( opening == '[' && closing == ']' ) return true;
    return false;
}
bool balanced_parentheses(char exp[], int x){
    int top = -1;
    char check[MAX];
    for(int i=0; i<x; i++){
        // PUSH
        if( exp[i] =='(' || exp[i] == '{' || exp[i] == '[' ){
            check[++top] = exp[i];
        }  
        else if( exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ){
            if( (top == -1) || !arePair(check[top], exp[i]) ){
                return false;
            }
        // POP
            top--;
        }
    }
    return (top==-1);
}
int main(){
    printf("Enter the expression: ");
    char exp[MAX];
    scanf("%50s", exp);
    if(balanced_parentheses(exp, strlen(exp))){
        printf("Balanced parenthese.\n");
    }
    else {
        printf("Parentheses are not Balanced."); 
    }
    return 0;
}