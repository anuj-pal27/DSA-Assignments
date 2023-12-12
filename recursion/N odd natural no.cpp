#include<iostream>
#include<stdio.h>
using namespace std;
void odd(int ,int );
int main(){
    int n,i;
    i=1;
    cout<<"Enter the element ";
    cin>>n;
    odd(n,i);
    return 0;
}
void odd(int n,int i){
   
    if(n==0)
        return ;
    else{
        cout<<i<<" ";
        i=i+2;
        odd(n-1,i);

    }    
}
