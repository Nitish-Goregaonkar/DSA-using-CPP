#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
        printf("Queue is Full!\n");
        return;
    }
    if (front == -1) {  // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = x;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  // queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60); // should say full
    display();
 return 0;
}