#include<iostream>
#include<stdio.h>
using namespace std;
void cube(int);
int main(){
    int n;
    cout<<"Enter the no ";
    cin>>n;
    cube(n);
    return 0;
}
void cube(int n){
   
    if(n==0)
        return ;
    else{
        cube(n-1);
        cout<<n*n*n<<" ";
    }    
}
