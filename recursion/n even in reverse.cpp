#include<iostream>
#include<stdio.h>
using namespace std;
void even(int ,int );
int main(){
    int n=2,i;
    cout<<"Enter the no ";
    cin>>i;
    even(n,i);
    return 0;
}
void even(int n,int i){
   
    if(n>i)
        return ;
    else{
        cout<<i<<" ";
        even(n,i-2);
    }    
}