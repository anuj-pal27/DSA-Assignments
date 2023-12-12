#include<iostream>
#include<stdio.h>
using namespace std;
void odd(int);
int main(){
    int n,i;
    i=1;
    cout<<"Enter the element ";
    cin>>n;
    odd(n);
    return 0;
}
void odd(int n){
   
    if(n==0)
        return ;
    else{
        n--;
        cout<<n<<" ";
        odd(n-1);

    }    
}