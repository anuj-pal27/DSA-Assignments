#include <iostream>
using namespace std;

class array
{
private:
    int capacity;
    int lastIndex = -1;
    int *ptr;

public:
    array(int);
    array(array &);
    bool isEmpty();
    void appendElement(int);
    void insertData(int, int);
    void delElement(int);
    bool isFull();
    int getElementbyIndex(int);
    int countElement();
    void edit(int, int);
    int elementFound(int);
    int getcapacity();
    ~array();
    void operator=(array &);
};
void array::operator=(array &arr)  //operator overloading
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if(ptr!=NULL)
        delete[] ptr;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        ptr[i] = arr.ptr[i];
}
int array::getcapacity()
{
    return capacity;
}
array::array(array &arr)
{
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++)
        ptr[i] = arr.ptr[i];
}
array::array(int size)
{
    ptr = new int[size];

    capacity = size;
}

bool array::isEmpty()
{
    return lastIndex == -1;
}

void array::appendElement(int value)
{
    if (lastIndex == capacity - 1)
        cout << "array is full" << endl;
    else
    {
        lastIndex++;
        ptr[lastIndex] = value;
    }
}

void array::insertData(int element, int index)
{
    if (lastIndex == capacity - 1)
        cout << "Array is full : no insertion can done" << endl;
    else if (index < 0 || index > lastIndex + 1)
        cout << "Invalid Index" << endl;
    else
    {
        for (int i = lastIndex; i >= index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = element;
        lastIndex++;
    }
}

array::~array()
{
    delete[] ptr;
}

void array::delElement(int index)
{
    if (isEmpty())
        cout << "Array is empty" << endl;

    else if (index < 0 || index > lastIndex)
        cout << "invalid index" << endl;

    else
    {
        for (int i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastIndex = -1;
    }
}

void array::edit(int index, int data)
{
    if (index >= 0 && index <= lastIndex)
        ptr[index] = data;
}

bool array::isFull()
{
    return lastIndex == capacity - 1;
}
int array::getElementbyIndex(int index)
{
    if (index >= 0 && index <= lastIndex)
        return ptr[index];
    cout << "Invalid index or empty array" << endl;
    return -1;
}

int array::countElement()
{
    return lastIndex + 1;
}

int array::elementFound(int element)
{
    int i = 0;
    for (i; i == capacity - 1; i++)
    {
        if (ptr[i] == element)
            return i;
    }
    return -1;
}

// int main()
// {

//     array obj(5);
//     if (obj.isEmpty())
//         cout << "Empty Array";
//     obj.appendElement(20);
//     obj.appendElement(40);
//     obj.appendElement(60);
//     obj.insertData(1, 30);

//     for (int i = 0; i < obj.countElement(); i++)
//         cout << obj.getElementbyIndex(i) << " ";
//     obj.delElement(2);
//     cout << endl;
//     for (int i = 0; i < obj.countElement(); i++)
//         cout << obj.getElementbyIndex(i) << " ";

//     cout << endl;
//     return 0;
// }
