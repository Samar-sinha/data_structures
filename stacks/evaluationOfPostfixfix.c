#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 101

bool isOperator(char operator){
    if(operator == '+' || operator == '-' || operator == '*' || operator == '/'){
        return true;
    }
    return false;
}

int operation(int op1, int op2, char operator){
    switch(operator){
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if(op2 == 0){
                printf("Error: Division by zero\n");
                exit(0);
            }
            return op1 / op2;
        default:
            printf("Unexpected error.\n");
            exit(0);
    }
}

bool isNumericdigit(char ch){
    if(ch >= '0' && ch <= '9') return true;
	return false;
}
int evaluate(char exp[], int x){
    int top = -1;
    int stack[MAX];
    for(int i=0; i<x; i++){
        // Scanning each character from left. 
		// If character is a delimitter, move on.
        if(exp[i] == ' ' || exp[i] == ',') continue;

        // If character is operator, pop two elements from stack, perform operation and push the result back. 
        else if(isOperator(exp[i])){
            // POPPING two operand
            int op2 = stack[top];
            top--;
            int op1 = stack[top];
            top--;
            // Performing operation
            int res = operation(op1, op2, exp[i]);
            // Pushing back the result onto the stack
            stack[++top] = res;
        }
        else if(isNumericdigit(exp[i])){
            // Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit.
            int operand = 0;
            while(i<x && isNumericdigit(exp[i])){
                // For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit.
                operand = (operand*10) + (exp[i] - '0');
                i++;
            }
            // Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice.
            i--;
            // Push operand on stack. 
			stack[++top] = operand;
        }
    }
    // If expression is in correct format, Stack will finally have one element. This will be the output. 
	return stack[top];
}
int main(){
    char exp[MAX];
    printf("Enter the postfix Expression: ");
    fgets(exp, MAX, stdin);
    // Remove trailing newline if any
    exp[strcspn(exp, "\n")] = '\0';
    int res = evaluate(exp, strlen(exp));
    printf("%d ",res);
    return 0;
}