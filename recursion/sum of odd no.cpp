#include<iostream>
#include<stdio.h>
using namespace std;
int oddSum(int );
int main(){
    int n;
    cout<<"Enter the no ";
    cin>>n;
    cout<<" "<<oddSum(n);
    return 0;
}
int oddSum(int n){
    if(n>0){
        n=n+ oddSum(n-1);
        
        return n;
    }
}