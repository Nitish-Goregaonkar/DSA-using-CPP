#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define max 100
int stack[max];
int top = -1;
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}
void push(int value)
{
    if(top==max-1){
        printf("Stack Underflow\n");
    }else{
        top++;
        stack[top]=value;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Stack underflow.\n");
    }
    else
    {
        int value = stack[top];
        top--;
        return value;
    }
}
int PostfixEvaluation(char *str)
{
    char operand[100];
    int index = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            operand[index] = str[i];
            index++;
        }
        else if (str[i] == ',')
        {
            if(index!=0){
            operand[index] = '\0';
            int num = atoi(operand);
            push(num);
            index = 0;
            }
        }
        else if (isOperator(str[i]))
        {
            int num2 = pop();
            int num1 = pop();
            int result;
            if (str[i] == '+')
            {
                result = num1 + num2;
                push(result);
            }
            else if (str[i] == '-')
            {
                result = num1 - num2;
                push(result);
            }
            else if (str[i] == '*')
            {
                result = num1 * num2;
                push(result);
            }
            else if (str[i] == '/')
            {
                result = num1 / num2;
                push(result);
            }
            else if (str[i] == '%')
            {
                result = num1 % num2;
                push(result);
            }
        }
    }
    int finalResult = stack[0];
    return finalResult;
}

int main()
{

    char exp[max];
    printf("Enter a postfix expression seperated by (,):");
    scanf("%s", exp);
    exp[strlen(exp)] = '\0';
    printf("Result is %d\n", PostfixEvaluation(exp));
 return 0;
}
