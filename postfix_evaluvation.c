#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <stdlib.h>  // for atoi()

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i, op1, op2;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        
        if (isdigit(ch)) {
            // convert char digit to int and push
            push(ch - '0');
        } else {
            // operator: pop two operands
            op1 = pop();
            op2 = pop();
            switch (ch) {
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1); break;
                case '*': push(op2 * op1); break;
                case '/': push(op2 / op1); break;
                case '^': {
                    int result = 1;
                    for (int j = 0; j < op1; j++) result *= op2;
                    push(result);
                    break;
                }
                default: 
                    printf("Invalid Operator: %c\n", ch);
                    exit(1);
            }
        }
    }
    return pop(); // final result
}

int main() {
    char exp[100];

    printf("Enter a postfix expression (e.g. 23*54*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

 return 0;
}
