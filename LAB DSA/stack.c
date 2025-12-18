#include <stdio.h>
#define MAX 100  
int stack [MAX];
int top = -1;
//function to push elements 
void push(int value){
    if (top== MAX -1){
        printf("Overflow cannot push %d \n", value);

    }else {top ++;
    stack[top]=value;
    printf("%d pushed to stack \n", value);
}

}
 
void pop (){
    if(top == -1){
        printf("%d stacked underflow, cant pop  \n", stack[top]);
        // top--;
    }
    else{
        printf("pop %d  from the stack \n", stack[top]);
        top--;
    }
}
int main(){
    push(10);
    push(10);
    push(10);
    push(10);
    for(int i=0;i<=top;i++){
        printf("%d ",stack[top]);
    }
    printf("\n");
     pop();
         for(int i=0;i<=top;i++){
        printf("%d ",stack[top]);
    }
    return 0;

}