#include <iostream>
#include <stdio.h>
using namespace std;

void bubbleSort(int arr[],int n){
    int t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[]={31,42,18,60,90};
    int N=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,N);
}