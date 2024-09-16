#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 6
class dequeueArray
{
private:
    int capacity;
    int rear;
    int front;
    int *ptr;
    int dequeue[MAX];

public:
    dequeueArray();
    ~dequeueArray();
    void insertAtRear(int);
    bool isEmpty();
    bool isFull();
    void insertAtFront(int);
    void deleteAtFront();
    void deleteAtBack();
    int getFront();
    int getRear();
};
int dequeueArray::getFront()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return -1;
    }
    return dequeue[front];
}
int dequeueArray::getRear()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return -1;
    }
    return dequeue[rear];
}
void dequeueArray::deleteAtFront()
{
    if (isEmpty())
    {
        cout << "underflow";
        return;
    }
    if (front == rear)
        front = rear = -1;
    if (front == MAX - 1)
        front = 0;
    else
        front++;
}
void dequeueArray::deleteAtBack()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return;
    }
    if (front == rear)
        front = rear = -1;
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
        rear--;
}
void dequeueArray::insertAtFront(int data)
{
    if (isFull())
    {
        cout << "Dequeue is Full\n";
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
        front--;
    dequeue[front] = data;
}
void dequeueArray::insertAtRear(int data)
{
    if (isEmpty())
        front = rear = 0;
    if (isFull())
    {
        cout << "dequeue is FULL\n";
        return;
    }
    else if (rear = MAX - 1)
        rear = 0;
    else
        rear++;
    dequeue[rear] = data;
}
bool dequeueArray::isFull()
{
    return front == 0 && rear == MAX - 1 || rear == front - 1;
}
bool dequeueArray::isEmpty()
{
    return rear == -1;
}
dequeueArray::dequeueArray()
{
    front = rear = -1;
    ptr = dequeue;
}

dequeueArray::~dequeueArray()
{   
    delete[]ptr;
}
