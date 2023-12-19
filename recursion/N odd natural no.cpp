#include<iostream>
#include<stdio.h>
using namespace std;
void odd(int ,int );
int main(){
    int n=1,i;
    cout<<"Enter the number ";
    cin>>i;
    odd(n,i);
    return 0;
}
void odd(int n,int i){
   
    if(n>i)
        return ;
    else{
        cout<<n<<" ";
        odd(n+2,i);
    }    
}
