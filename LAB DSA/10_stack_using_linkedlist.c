#include <stdio.h>
#include <stdlib.h>
struct node{
    int data ;
     struct node* link;
};
struct node *start, *newnode , *temp;
void push(int item ){
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode -> data=item;
    newnode -> link=NULL;
    if (start==NULL){
        start=newnode;
    }
    else{
        newnode -> link =start;
        start =newnode ;

    }
}
void pop(){
    if (start != NULL){
    start = start -> link;

    }
    else{
        printf("underflow");
    }

}
int display(){
    temp=start;
    while (temp->link!=NULL){
        printf("%d ", temp->data);
        temp =temp->link;
    }
}
int main(){

    start = (struct node *)malloc(sizeof(struct node));
    start -> link=NULL;
 push(10);
 push(20);
 push(30);
 push(40);
 push(50);
 printf("statck elememnts:\n");
 display();
 pop();
 pop();

 printf("after deletion stack elemtnts are :- \n");
 display();
 return 0;
}