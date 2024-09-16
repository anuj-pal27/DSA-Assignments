#include <iostream>
using namespace std;

class array
{
public:
    void sortArray(int *, int);
    void maxValue(int *, int);
    void smallValue(int *, int);
    void sumElements(int *, int);
    void averageElements(int *, int);
    void rotateArray(int *, int);
    void duplicateRemove(int *, int);
};

void array::rotateArray(int arr[], int size)
{
    int i, j;
    int temp = 0;
    for (i = size - 1; i > 0; i--)
    {
        temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
    }
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}
void array::sumElements(int arr[], int size)
{
    int i, j, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    cout << sum;
}
void array::averageElements(int arr[], int size)
{
    int i, j, sum = 0;
    for (i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    sum = sum / size;
    cout << sum;
}
void array::sortArray(int arr[], int size)
{
    int temp;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i+1 ;j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < 5; i++)
        cout << arr[i] << " ";
}
void array::maxValue(int arr[], int size)
{
    int i, j;
    int max = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
}
void array::smallValue(int arr[], int size)
{
    int i, j;
    int max = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] < max)
        {
            max = arr[i];
        }
    }
    cout << max << endl;
}

int main(){

    return 0;
}