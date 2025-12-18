#include <stdio.h>
#include <stdlib.h>
#define MAX 100
    
struct Stack
{
    int arr[MAX];
    int top;
};

struct Stack s1, s2;

void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = x;
    }
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty!\n");
        return -1; // ✅ Added return to prevent undefined behavior
    }
    else
    {
        int item = s->arr[s->top];
        s->top--;
        return item;
    }
}

void enqueue(int x)
{
    if (s1.top == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    else
    {
        push(&s1, x);
    }
}

int dequeue()
{
    if (s1.top == -1)
    {
        printf("Queue is underflow\n");
        return -1; // ✅ Added return to avoid undefined behavior
    }

    while (s1.top != -1)
    {
        int temp = pop(&s1);
        push(&s2, temp);
    }

    int item = pop(&s2);

    while (s2.top != -1)
    {
        int temp = pop(&s2);
        push(&s1, temp);
    }

    return item; // ✅ Added missing return statement
}

void display()
{
    if (s1.top == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue Elements: \n");
        for (int i = 0; i <= s1.top; i++)
        {
            printf("%d ", s1.arr[i]);
        }
        printf("\n"); // ✅ Added newline for clean output
    }
}

int main()
{
    initStack(&s1);
    initStack(&s2);

    enqueue(10);
    enqueue(20);
    enqueue(39);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    enqueue(10);
    enqueue(20);
    enqueue(39);
    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}


