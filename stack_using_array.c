#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty(void) {
    return top == -1;
}

int isFull(void) {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d.\n", x);
        return;
    }
    stack[++top] = x;
    printf("Pushed: %d\n", x);
}

int pop(void) {
    if (isEmpty()) {
        printf("Stack underflow! Nothing to pop.\n");
        return -1; // sentinel for error
    }
    return stack[top--];
}

int peek(void) {
    if (isEmpty()) {
        printf("Stack is empty. No top element.\n");
        return -1;
    }
    return stack[top];
}

void display(void) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) == 1) push(value);
                else { printf("Invalid value.\n"); return 0; }
                break;
            case 2: {
                int popped = pop();
                if (popped != -1) printf("Popped: %d\n", popped);
                break;
            }
            case 3: {
                int topVal = peek();
                if (topVal != -1) printf("Top element: %d\n", topVal);
                break;
            }
            case 4:
                display();
                break;
            case 5:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Please enter a valid option (1-5).\n");
        }
    }
    return 0;
}



#include <stdio.h>

#define MAX 5

int main() {
    int stack[MAX];
    int top = -1; // empty stack

    // Push elements
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    // Display stack
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    // Pop element
    int popped = stack[top--];
    printf("Popped: %d\n", popped);

    // Display stack again
    printf("Stack after pop:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }

    return 0;
}
