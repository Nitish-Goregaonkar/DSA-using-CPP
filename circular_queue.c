// #include <stdio.h>
// #define SIZE 5

// int queue[SIZE];
// int front = -1, rear = -1;

// void enqueue(int x) {
//     if ((front == 0 && rear == SIZE-1) || (front == rear+1)) {
//         printf("Queue is Full!\n");
//         return;
//     }
//     if (front == -1) {  // first element
//         front = rear = 0;
//     } else {
//         rear = (rear + 1) % SIZE;
//     }
//     queue[rear] = x;
// }

// void dequeue() {
//     if (front == -1) {
//         printf("Queue is Empty!\n");
//         return;
//     }
//     printf("Deleted: %d\n", queue[front]);
//     if (front == rear) {
//         front = rear = -1;  // queue becomes empty
//     } else {
//         front = (front + 1) % SIZE;
//     }
// }

// void display() {
//     if (front == -1) {
//         printf("Queue is Empty!\n");
//         return;
//     }
//     printf("Queue: ");
//     int i = front;
//     while (1) {
//         printf("%d ", queue[i]);
//         if (i == rear) break;
//         i = (i + 1) % SIZE;
//     }
//     printf("\n");
// }

// int main() {
//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     display();
//     dequeue();
//     enqueue(40);
//     enqueue(50);
//     enqueue(60); // should say full
//     display();
//    return 0;
// }

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert(int item) {
    if ((rear+1)%SIZE==front) {
        printf("Queue is full\n");
    } else {
        if (front == -1 && rear ==-1) {  // first insertion
            front = 0;
            rear =0;
        }else{
        rear =(rear+1)%SIZE;}
        queue[rear] = item;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
      
        if (front == rear) {  // queue is empty again
            front = rear = -1;
        }
        else{
            front=(front+1)%SIZE;

        }
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
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Queue after insertion:\n");
    display();

    delete();
    insert(60);
    delete();
    // // insert(70);
    // // insert(80);
    // delete();
    printf("Queue after deletion:\n");
    display();

    return 0;
}
