#include<iostream>
#include<stdio.h>
using namespace std;
void even(int ,int );
int main(){
    int n,i;
    i=1;
    cout<<"Enter the element ";
    cin>>n;
    even(n,i);
    return 0;
}
void even(int n,int i){
   
    if(n==0)
        return ;
    else{
        cout<<i<<" ";
        i++;
        even(n-1,i);
    }    
}