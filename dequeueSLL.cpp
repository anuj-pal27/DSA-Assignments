#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    node *prev;
    int item;
    node *next;
};
class dequeueSLL
{
private:
    node *front;
    node *rear;

public:
    dequeueSLL();
    ~dequeueSLL();
    void insertAtRear(int);
    bool isEmpty();
    void insertAtFront(int);
    void deleteAtFront();
    void deleteAtBack();
    int getFront();
    int getRear();
    dequeueSLL(dequeueSLL &);
};

dequeueSLL::dequeueSLL(dequeueSLL &D){
    
}
dequeueSLL::~dequeueSLL()
{
    while(front){
        deleteAtFront();

    }
}
void dequeueSLL::deleteAtBack()
{
    node *t;
    if (isEmpty())
    {
        cout << "UNDERFLOW\n";
        return;
    }
    t = rear;
    if(front==rear)
        rear=front=NULL;
    else{
    rear = rear->prev;
    rear->next=NULL;
    }
    delete t;
}
void dequeueSLL::deleteAtFront()
{
    node *t;
    if (isEmpty())
    {
        cout << "UNDERFLOW\n";
        return;
    }
    t = front;
    if (front == rear)
        front = rear = NULL;
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    delete t;
}
int dequeueSLL::getFront()
{
    if (isEmpty())
    {
        cout << "Dequeue is Empty UNDERFLOW\n";
        return -1;
    }
    return front->item;
}
int dequeueSLL::getRear()
{
    if (isEmpty())
    {
        cout << "Dequeue is Empty UNDERFLOW\n";
        return -1;
    }
    return rear->item;
}
void dequeueSLL::insertAtFront(int data)
{
    node *n;
    n = new node;
    n->item = data;
    n->next = front;
    if (front)
        front->prev = n;
    else
        rear = n;
    front = n;
}
bool dequeueSLL::isEmpty()
{
    return front == NULL;
}
void dequeueSLL::insertAtRear(int data)
{
    node *n;
    n = new node;
    n->item = data;
    n->prev = rear;
    n->next = NULL;
    if (rear)
        rear->next = n;
    else
        front = n;
    rear = n;
}
dequeueSLL::dequeueSLL()
{
    front = NULL;
    rear = NULL;
}
