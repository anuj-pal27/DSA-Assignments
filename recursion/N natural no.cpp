#include<iostream>
#include<stdio.h>
using namespace std;
void naturalno(int ,int );
int main(){
    int n,i;
    i=1;
    cout<<"Enter the element ";
    cin>>n;
    naturalno(n,i);
    return 0;
}
void naturalno(int n,int i){
   
    if(n==0)
        return ;
    else{
        cout<<i<<" ";
        i++;
        naturalno(n-1,i);

    }    
}
