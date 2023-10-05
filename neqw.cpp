#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {20, 400, 30, 50, 80};
    int size = 5;
    int i, j;
    int max=arr[0];
    for (i = 1; i < size; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    
    }
    cout<<max<<endl;
}