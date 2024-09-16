#include<iostream>
#include<stdio.h>
using namespace std;
int sum(int);
int main(){
    int n;
    cout<<"Enter the no ";
    cin>>n;
    int result = sum(n);
    cout<<result;
    return 0;
}
int sum(int n){
    if(n==1)
        return 1;
    return n+sum(n-1);
}