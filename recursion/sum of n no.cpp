#include<iostream>
#include<stdio.h>
using namespace std;
int sumN(int );
int main(){
    int n;
    cout<<"Enter the no ";
    cin>>n;
    cout<<" "<<sumN(n);
    return 0;
}
int sumN(int n){
    if(n>0){
        n=n+sumN(n-1);
        return n;
    }
}