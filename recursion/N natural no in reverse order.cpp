#include <iostream>
#include <stdio.h>
using namespace std;
void naturalno(int);
int main()
{
    int n;
    cout << "Enter the element ";
    cin >> n;
    naturalno(n);
    return 0;
}
void naturalno(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        naturalno(n - 1);
    }
}
