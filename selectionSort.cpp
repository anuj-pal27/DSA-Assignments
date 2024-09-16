#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int arr[9] = {38,90,47,69,52,88,71,18,20};
    int n=9,t;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
              t=arr[i];
              arr[i]=arr[j];
              arr[j]=t;
            
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}