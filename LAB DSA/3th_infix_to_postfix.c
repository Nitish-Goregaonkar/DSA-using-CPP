#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
char pop()
{
    return stack[top--];
}
void push(char item)
{
    top = top + 1;
    stack[top] = item;
}
int precedence(char symbol)
{
    if (symbol == '^')
    {
        return 3;
    }
    if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    return 0;
}

void infixtpostfix(char infix[], char postfix[])
{
    char symbol;
    int n=strlen(infix);
    infix[n] = ')';
    infix[++n] = '\0';
    push('(');
    int k=0;
    for (int i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (isalnum(symbol))
        {
            postfix[k] = symbol;
            k++;
        }
        else if ((symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^') && symbol != '(' && symbol != ')')
        {
            while (precedence(symbol) <= precedence(stack[top]))
            {
                postfix[k] = pop();
                k++;
            }
            push(symbol);
        }
         else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (stack[top]!='(')
            {
                postfix[k++] = pop();

            }
             pop();
        }
    }
     while (top != -1){
        postfix[k++] = pop();
     }
    postfix[k]='\0';
}
int main()
{
    char postfix[MAX];
    char infix[MAX];
    printf("Enter Expresion: ");
    gets(infix);
    infixtpostfix(infix,postfix);
    printf("Postfix Expression: %s\n",postfix);
 return 0;
}
