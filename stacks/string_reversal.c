// string reversal using stack
#include<stdio.h>
#include<string.h>
#define MAX 51
void reverse(char str[], int n){
    int top = -1;
    char stack[MAX];
    // push
    for(int i=0; i<n; i++){
        if(top == MAX-1){
        printf("error: stack overflow\n");
        return;
        }
        stack[++top] = str[i];
    }
    // pop
    for(int i=0; i<n; i++){
        str[i] = stack[top--];
    }
}
int main(){
    char str[MAX];
    puts("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    // scanf("%[^\n]",str);
    reverse(str, strlen(str));
    printf("Output = %s\n",str);
    return 0;
}