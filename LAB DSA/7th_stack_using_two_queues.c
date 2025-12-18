#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct Queue {
    int arr[SIZE];
    int front, rear;
};

struct Queue q1, q2;

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = x;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return val;
}

void push(int x) {
    enqueue(&q2, x);

    while (!isEmpty(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }

    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

int pop() {
    if (isEmpty(&q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&q1);
}

void display() {
    if (isEmpty(&q1)) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (int i = q1.front; i <= q1.rear; i++)
        printf("%d ", q1.arr[i]);

    printf("\n");
}

int main() {
    initQueue(&q1);
    initQueue(&q2);

    push(10);
    push(20);
    push(30);
    push(40);

    display();

    pop();
    pop();

    display();
}
