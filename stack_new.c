// // #include <stdio.h>
// // #define MAX 5   // maximum size of stack 

// // int stack[MAX];
// // int top = -1;

// // // Function to push element
// // void push(int value) {
// //     if (top == MAX - 1) {
// //         printf("Stack Overflow! Cannot push %d\n", value);
// //     } else {
// //         top++;
// //         stack[top] = value;
// //         printf("%d pushed to stack\n", value);
// //     }
// // }

// // // Function to pop element
// // void pop() {
// //     if (top == -1) {
// //         printf("Stack Underflow! Cannot pop\n");
// //     } else {
// //         printf("%d popped from stack\n", stack[top]);
// //         top--;
// //     }
// // }

// // // Function to display stack
// // void display() {
// //     if (top == -1) {
// //         printf("Stack is empty!\n");
// //     } else {
// //         printf("Stack elements: ");
// //         for (int i = 0; i <= top; i++) {
// //             printf("%d ", stack[i]);
// //         }
// //         printf("\n");
// //     }
// // }

// // // Main function
// // int main() {
// //     int choice, value;

// //     while (1) {
// //         printf("\n--- Stack Menu ---\n");
// //         printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
// //         printf("Enter your choice: ");
// //         scanf("%d", &choice);

// //         switch (choice) {
// //         case 1:
// //             printf("Enter value to push: ");
// //             scanf("%d", &value);
// //             push(value);
// //             break;
// //         case 2:
// //             pop();
// //             break;
// //         case 3:
// //             display();
// //             break;
// //         case 4:
// //             return 0;
// //         default:
// //             printf("Invalid choice! Try again.\n");
// //         }}}


// #include <stdio.h>
// #define MAX 100
// int stack[MAX];
// int top = -1;
// //function to push elements into the stacks 
// void push(int value){
//         if (top == -1){
//             printf("Overflow!!, cannot push %d \n", value );
//         }
//         else{
//             top ++;
//             stack[top]=value ;
//             printf("Pushed into the stack \n", value);
//         }
// }
// // function to pop the elements from the stack
// void pop(){
//     if(top ==-1){
//         printf("%d stack underflow!! cannot pop the element \n");
//     }
//     else{
//         printf("%d element has been popped from the stack \n", stack[top]);
//         top--;
//     }
// }


// void display (){
//     if (top ==-1){
//         printf("no element present in there in the stack \n");

//     }
//     else{
//         printf("elements inside the stacks are \n ");
//         for (int i=0; i<=top; i++){
//             printf("%d", stack[i]);
//         }printf("\n");
//     }
// }
// int main (){
//     int choice, value;
//     while(choice !=4){
//         printf("Stack Operation  \n");
//         printf("1. Push \n 2.Pop \n 3. Display 4.Exit \n");
//         printf("enter your choice:-");
//         scanf("%d", &choice);
//         if (choice ==1){
//             printf("enter the value to be added:-  \n");
//             scanf("%d", &value);
//             push (value);}
//             else if( choice ==2){
//                 pop();

//             }
//             else if (choice ==3){
//               display();
//             }
      
//     }}