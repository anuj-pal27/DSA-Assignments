#include<iostream>
#include<stdio.h>
using namespace std;
void square(int);
int main(){
    int n;
    cout<<"Enter the no ";
    cin>>n;
    square(n);
    return 0;
}
void square(int n){
   
    if(n==0)
        return ;
    else{
        cout<<n*n<<" ";
        square(n-1);
    }    
}