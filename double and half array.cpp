#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex = -1;
    int *ptr;

public:
    Array(int);

    void getArray();
    void append(int);
    void inserElement(int, int);
    void deleteElement(int);
    void count();
    int capacity();
    bool isEmpty();

    void halfarray()
    {
        int *newptr = new int[capacity / 2];
        for (int i = 0; i <= lastIndex; i++)
        {
            newptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newptr;
        capacity = capacity / 2;
    }
    void doubleArray()
    {
        int *newptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++)
        {
            newptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newptr;
        capacity *= 2;
    }
};

bool Array::isEmpty()
{
    return lastIndex == -1;
}
int Array::capacity()
{
    return capacity;
}

void Array::deleteElement(int index)
{
    if (index > lastIndex || index < 0)
    {
        cout << "invalid index";
    }
    else
    {
        if (capacity/2 >= lastIndex+1 && capacity>1)
            halfarray();

        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex = -1;
    }
}

void Array::count()
{
    cout << lastIndex + 1 << endl;
}
void Array::inserElement(int element, int index)
{

    if (index < 0 || index > lastIndex + 1)
        cout << "Invalid Index" << endl;
    else
    {
        if (lastIndex == capacity - 1)
            doubleArray();
        for (int i = lastIndex; i >= index; i--)
            ptr[i] = ptr[i - 1];
        ptr[index] = element;
        lastIndex++;
    }
}
void Array::append(int value)
{
    if (lastIndex == capacity - 1)
        doubleArray();

    lastIndex++;
    ptr[lastIndex] = value;
}

Array::Array(int size)
{
    ptr = new int[size];
    capacity = size;
}

void Array::getArray()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << ptr[i] << " ";
    }
}

int main()
{
    Array obj(5);
    obj.append(2);
    obj.append(3);
    obj.append(4);
    obj.append(5);

    obj.append(2);
    // obj.append(3);
    // obj.append(4);
    // obj.append(5);
    // obj.append(6);
    // obj.append(6);
    //     obj.deleteElement(0);
    //   obj.deleteElement(1);

    obj.getArray();

    return 0;
}