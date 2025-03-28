#include<iostream> 
using namespace std; 
#define MAX 100 
int main() 
{ 
int j,k,n,item ;
int LA[MAX]; 
cout<<"Enter size and elements of the array\n"; 
cin>>n; 
for(j=0;j<n;j++) 
cin>>LA[j]; 
cout<<"*****Array before deletion********\n"; 
for(j=0;j<n;j++) 
cout<<LA[j]<<"\t"; 
cout<<"\n"; 
cout<<"Enter the position of element you want to delete\n"; 
cin>>k ;
item=LA[k-1]; 
LA[j]=LA[j+1]; 
n=n-1;: 
cout<<"*****Array after deletion********\n"; 
for(j=0;j<n;j++), 
halore t 
cout<<LA[j]<<"\t"; 
cout<<"\n"; 
return 0;