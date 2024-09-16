#include<iostream>
using namespace std;

int partition(int arr[],int left,int right){
    int pivot=left;
    while(left!=right){
        if (arr[left] > arr[right]) {
            swap(arr[left], arr[right]);

            // Update pivot only if the swap is performed
            if (pivot == left) {
                pivot = right;
                left++;
            }
            else {
                pivot = left;
                right--;
            }
        }
        else {
            // No swap, just move the pointers
            if (pivot == right)
                left++;
            else
                right--;
        }
    }
    return pivot;

}   

void quickSort(int arr[],int left,int right){
    if(left<right){
        int p=partition(arr,left,right);
        quickSort(arr,left,p-1);
        quickSort(arr,p+1,right);
    }
}
void  printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
}
int main(){
    int arr[]={24,9,29,14,19,27};
    int N=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,N-1);
    printArr(arr,N);
}