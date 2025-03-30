#include <iostream>
#include <stdlib.h>
#include <malloc.h>

using namespace std;

#define MAX 100

struct node {
    int info;
    struct node *link;
} *start = NULL;

int main() {
    int i = 0, item, data, count = 0, flag = 0;
    struct node *ptr;
    struct node *temp_start;

    cout << "Enter the size of the linked list\n";
    cin >>n;

    do {
        cin >> data;
        struct node *temp = new struct node;
        temp->info = data;
        temp->link = NULL;

        if (start == NULL)
            start = temp;
        else {
            ptr=start; 
while(ptr->link!=NULL) 
ptr=ptr->link; 
ptr->link=temp; }
i=i+1; 
} 
while(i<n); 
cout<<"Elements in the linked list are as follows:\n"; 
struct node *p; 
p=start; 
while(p!=NULL) 
{ 
cout<<p->info<<"\t"; 
p=p->link; 
} 
cout<<"\n"; 
cout<<"Enter the element you want to search\n"; 
cin>>item; 
//Searching in an unsorted linked list 
struct node *q; 
q=start; 
while(q!=NULL){ 
count++; 
if(q->info==item) 
{ 
cout<<"Element found at position "<<count<<"\n"; 
flag=1; 
break;
}
else
q=q->link;
}
if(flag==0)
count<<"element not found\n";
return 0;
}
            