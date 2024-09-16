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
    if(i==0)
        return ;
    else{
        cout<<n<<" ";
        i--;
        odd(n+2,i);
    }    
}

// void odd(int n){
//     if(n > 0){
//         odd(n-1);
//         cout<<" "<<2*(n-1);
//     }
// }