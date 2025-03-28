#include<iostream>
using namespace std; 
#define MAX 100 
int main(){

int  j,n,k,item;
int LA[MAX]; 
//Creation of a of an array demont 
cout<<"Enter the size and elements of an array:\n"; 
cin>>n;
for(j=0;j<n;j++) 
cin>>LA[j];

cout<<"!!***** Array before INSERTION**********\n"; 
//Displaying the elements of an array 
for(j=0;j<n;j++) 
cout<<LA[j]<<"\t"; 
cout<<"\n"; 
//Insertion, of element in an array 
cout<<"Enter the element you want to insert and its position"; 
cin>>item>>k ;
for(j=n-1;j>=k-1;j--){
    LA[j+1]=LA[j];
}
LA[k-1]=item;
n=n+1;
cout<<"!!***** Array after INSERTION**********\n"; 
//displaying the elements
for(j=0;j<n;j++)
cout<<LA[j]<<"\t";
cout<<"\n";
return 0;
}