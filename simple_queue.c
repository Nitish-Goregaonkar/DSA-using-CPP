#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {  // first insertion
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
        if (front > rear) {  // queue is empty again
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue data: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Queue after insertion:\n");
    display();

    delete();
    printf("Queue after deletion:\n");
    display();

    return 0;
}
