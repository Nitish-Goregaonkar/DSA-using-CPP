// // #include<stdio.h>
// // #include<stdlib.h>
// // #define size 5
// // struct queue
// // {
// //     int arr[size];
// //     int front, rear;
// // };
// // struct queue q1, q2;
// // void init(struct queue s){
// //     s.front=-1;
// //     s.rear=-1;
// // }
// // void insert(struct queue s,int item) {
// //     if (s.rear == size - 1) {
// //         printf("Stack is full\n");
// //     } else {
// //         if (s.front == -1) {  // first insertion
// //             s.front = 0;
// //         }
// //         s.rear++;
// //         s.arr[s.rear] = item;
// //     }
// // }

// // int delete(struct queue s) {
// //     if (s.front == -1) {
// //         printf("Stack is empty\n");
// //         // return ;
// //     } else {
// //         // printf("Deleted: %d\n", s.arr[s.front]);
// //         int item=s.arr[s.front];
// //         s.front++;
// //         if (s.front > s.rear) {  // queue is empty again
// //             s.front = s.rear = -1;
// //         }
// //         return item;
// //     }
// // }

// // void push(int item){
// //    insert(q1,item);
// // }
// // void pop(){
// //     while(q1.front <q1.rear){
// //         insert(q2, delete(q1));
        
// //     }
// // }

// // void display() {
// //     if (q1.front == -1) {
// //         printf("Stack is empty\n");
// //         // return -1;
// //     }
// //     printf("Stack data: ");
// //     for (int i = q1.front; i <= q1.rear; i++) {
// //         printf("%d ", q1.arr[i]);
// //     }
// //     printf("\n");
// // }
// // int main(){
// // push(10);
// // push (20);
// // push (50);
// // push(45);
// // pop();
// // pop();
// // display();
// // return 0;
// // }

//gemini 
// #include <stdio.h>
// #include <stdlib.h>

// #define size 5 // Max capacity of the queue/stack

// // Structure definition for a Queue
// struct Queue
// {
//     int arr[size];
//     int front, rear;
// };

// // Global queues used to implement the stack
// struct Queue s1, s2;

// // Initializes a queue to an empty state
// void init(struct Queue *s)
// {
//     s->front = -1;
//     s->rear = -1;
// }

// // Enqueues an item into the queue (O(1) time)
// // front: index of the first element
// // rear: index one past the last element (the next available slot)
// void insert(struct Queue *s, int item)
// {
//     // Check for overflow: 'rear' points to the next available slot.
//     // If rear equals 'size', the array is full.
//     if (s->rear == size)
//     {
//         printf("Queue Overflow\n");
//     }
//     else
//     {
//         // If the queue was empty, set 'front' to 0
//         if (s->front == -1)
//         {
//             s->front = 0;
//             s->rear = 0; // Initialize rear to 0 (the first available slot)
//         }
        
//         s->arr[s->rear] = item;
//         s->rear = s->rear + 1; // Move rear to the next available slot
//     }
// }

// // Dequeues an item from the front of the queue (O(1) time)
// int delete(struct Queue *s)
// {
//     // Check for underflow: queue is empty if front is -1 (initial state)
//     // or if front catches up to rear.
//     if (s->front == -1 || s->front == s->rear)
//     {
//         printf("Queue Underflow \n");
//         // Reset pointers to the empty state before returning error value
//         s->front = s->rear = -1;
//         return -1;
//     }
//     else
//     {
//         int item = s->arr[s->front];
//         s->front++; // Move front to the next element
        
//         // Check if the last element was just deleted (front == rear)
//         if (s->front == s->rear)
//         {
//             s->front = s->rear = -1; // Reset to the empty state
//         }
//         return item;
//     }
// }

// // Stack push operation (O(1) time complexity)
// // Elements are simply enqueued into the primary queue (s1)
// void push(int item)
// {
//     insert(&s1, item);
// }

// // Stack pop operation (O(N) time complexity)
// // Moves N-1 elements, deletes the last element, and swaps queues.
// int pop()
// {
//     // Stack underflow check (same as queue underflow on s1)
//     if (s1.front == -1 || s1.front == s1.rear)
//     {
//         printf("Stack underflow!\n");
//         return -1;
//     }

//     // Move N-1 elements from s1 to s2, leaving only the last element (stack's top) in s1.
//     // The number of elements remaining in s1 is (s1.rear - s1.front).
//     // Loop while the count is greater than 1.
//     while ((s1.rear - s1.front) > 1)
//     {
//         // Dequeue from s1 and Enqueue into s2
//         insert(&s2, delete(&s1));
//     }

//     // s1 now contains only the top element of the stack.
//     int item = delete(&s1);

//     // Swap the names of the queues (s1 <-> s2). This makes the new s1 (the old s2) 
//     // the main queue containing all the remaining elements in stack order.
//     // The swap operation is O(1) as it only swaps pointers/struct contents.
//     struct Queue temp = s1;
//     s1 = s2;
//     s2 = temp;
    
//     // After the swap, the old s1 (now s2) is empty, ready for the next operation.
//     init(&s2); // Re-initialize the now empty queue (s2)

//     return item;
// }

// // Displays the stack elements (same as displaying queue s1)
// void display()
// {
//     if (s1.front == -1 || s1.front == s1.rear)
//     {
//         printf("Stack is Empty!\n");
//         return;
//     }
    
//     printf("Stack Elements (Top to Bottom):\n");
//     // Iterate from front up to (but not including) rear
//     for (int i = s1.rear - 1; i >= s1.front; i--)
//     {
//         printf("%d ", s1.arr[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     init(&s1);
//     init(&s2);

//     printf("--- Stack Implementation (Push O(1), Pop O(N)) ---\n");

//     push(10);
//     printf("Pushed 10\n");
//     push(20);
//     printf("Pushed 20\n");
//     push(30);
//     printf("Pushed 30\n");
    
//     display(); // Should print 30 20 10 (Stack order)

//     printf("Popped: %d\n", pop()); // Should pop 30
//     printf("Popped: %d\n", pop()); // Should pop 20
    
//     display(); // Should print 10

//     push(40);
//     printf("Pushed 40\n");
//     push(50);
//     printf("Pushed 50\n");
    
//     display(); // Should print 50 40 10

//     printf("Popped: %d\n", pop()); // Should pop 50
//     printf("Popped: %d\n", pop()); // Should pop 40
//     printf("Popped: %d\n", pop()); // Should pop 10
    
//     display(); // Should show Stack is Empty!
//     printf("Popped: %d\n", pop()); // Stack underflow check

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#define size 5

struct Queue {
    int arr[size];
    int front, rear;
};

struct Queue s1, s2;

void init(struct Queue *s) {
    s->front = -1;
    s->rear = -1;
}

void insert(struct Queue *s, int item) {
    if (s->rear == size - 1) {
        printf("Queue Overflow\n");
    } else {
        if (s->rear == -1) {
            s->front = 0;
            s->rear = 0;
        } else {
            s->rear++;
        }
        s->arr[s->rear] = item;
    }
}

int delete(struct Queue *s) {
    if (s->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int item = s->arr[s->front];
        if (s->front == s->rear) {
            s->front = s->rear = -1;
        } else {
            s->front++;
        }
        return item;
    }
}

void push(int item) {
    insert(&s1, item);
}

int pop() {
    if (s1.front == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }

    // Move all elements except last from s1 to s2
    while (s1.front != s1.rear) {
        insert(&s2, delete(&s1));
    }

    // Delete last element (top of stack)
    int item = delete(&s1);

    // Swap s1 and s2
    struct Queue temp = s1;
    s1 = s2;
    s2 = temp;

    // Reset s2 for next use
    init(&s2);

    return item;
}

void display() {
    if (s1.front == -1) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack Elements:\n");
    for (int i = s1.front; i <= s1.rear; i++) {
        printf("%d ", s1.arr[i]);
    }
    printf("\n");
}

int main() {
    init(&s1);
    init(&s2);

    push(10);
    push(20);
    push(30);
    display();

    pop();
    pop();
    display();

    push(40);
    push(50);
    display();

return 0;
}

