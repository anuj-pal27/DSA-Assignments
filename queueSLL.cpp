#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};

class queue
{
private:
    node *rear;
    node *front;

public:
    queue();
    void inserting(int);
    bool isEmpty();
    int getRear();
    int getFront();
    void deleting();
    int count();
    ~queue();
};

int queue::count(){
    node *ptr;
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    return c;
}
queue::~queue(){
    while(front==NULL)
        deleting();
}
void queue::deleting()
{
    node *ptr;
    ptr = front;
    if(!isEmpty()){
        ptr=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        delete ptr;
    }
}
int queue::getFront()
{
    if (isEmpty())
        return -1;
    return front->item;
}
int queue::getRear()
{
    if (isEmpty())
        return -1;
    return rear->item;
}

queue::queue()
{
    front = NULL;
    rear = NULL;
}
bool queue::isEmpty()
{
    return rear == NULL;
}
void queue::inserting(int data)
{
    node *n;
    n = new node;
    n->item = data;
    if (isEmpty())
    {
        rear = n;
        front = n;
    }
    else
    {
        rear->next = n;
        rear = n;
        rear->next = NULL;
    }
}

int main()
{

    return 0;
}