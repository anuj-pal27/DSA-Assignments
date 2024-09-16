#include <iostream>

using namespace std;
class heap
{
private:
    int capacity;
    int *ptr;
    int lastIndex = -1;

public:
    heap(int);
    void insert(int);
    void doubleArray();
    int size();
    bool isEmpty();
    bool isFull();
    int max();
    void del();
};
void heap::del(){
    
}

int heap::max(){
    if(!isEmpty())
        return ptr[0];
    else
        throw -1;
}
heap::heap(int size)
{
    ptr = new int[size];
    capacity = size;
}

void heap::insert(int data)
{
    int index, parIndex;
    isFull(){
        doubleArray();
    }
    for (index = lastIndex+1; index > 0; index = parIndex)
    {
        parIndex=(index-1)/2;
        if(ptr[parIndex]<data)
            ptr[index]=ptr[parIndex];
        else
            break;
    }
    ptr[index]=data;
    lastIndex++;
}

void heap::doubleArray()
{
    int *temp=new int[capacity*2];
    for(int i=0;i<=lastIndex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*=2;
}

int heap::size()
{
    return capacity;
}

bool heap::isEmpty()
{
    return lastIndex==-1;
}
bool heap::isFull()
{
    return lastIndex==capacity-1;
}
int main()
{
}