#include<iostream>
#include<stdio.h>
using namespace std;

void insertionSort(int arr[],int n){
    int i=0,j,key;
    for(int i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&& arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++)
        cout<<" "<<arr[i];
}

int main(){
    int arr[]={50,20,37,91,64,18,43,59,72,81};
    int N=sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr,N);
    return 0;
}