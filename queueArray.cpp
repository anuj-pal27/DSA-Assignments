#include <iostream>
#include <conio.h>
using namespace std;
class queue
{
private:
    int capacity;
    int *ptr;
    int front, rear;

public:
    queue(int);
    queue(queue &);
    void insertion(int);
    int rearView();
    int frontView();
    bool isFull();
    bool isEmpty();
    void deletion();
    ~queue();
    int count();
    queue& operator=(queue &);
};
int queue::count(){
    if(isEmpty())
        return 0;
    if(front<=rear)
        return rear-front+1;
    return capacity-front+rear+1;
}
queue::queue(queue &Q){
    capacity=Q.capacity;
    front = Q.front;
    rear = Q.rear;
    ptr=new int[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n){
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
queue& queue:: operator=(queue &Q){
    capacity=Q.capacity;
    front = Q.front;
    rear = Q.rear;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    int n=Q.count();
    int i=Q.front;
    while(n){
        ptr[i]=Q.ptr[i];
        if(i==capacity-1)
            i=0;
        else
            i++;
        n--;
    }
}
queue::~queue(){
    delete []ptr;
}
void queue::deletion()
{
    if (isEmpty())
        cout << "\n Queue is Empty Underflow";
    else if (front == rear)
        front = rear = -1;
    else if(front==capacity-1)
        front =0;
    else
        front++;
}
bool queue::isEmpty()
{
    return rear == -1;
}
bool queue::isFull()
{
    return (((front == 0) && (rear == capacity - 1)) || (rear == front - 1));
}
queue::queue(int size)
{
    ptr = new int[size];
    capacity = size;
    front = -1;
    rear = -1;
}

void queue::insertion(int data)
{
    if (isFull())
        cout << "\nQueue is FUll Overflow";
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        ptr[rear] = data;
    }

    else if (rear == capacity - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }
    else
    {
        rear++;
        ptr[rear] = data;
    }
}

int queue::rearView()
{
    if (!isEmpty())
        return ptr[rear];
    cout << "\n Queue is Empty";
    return -1;
}

int queue::frontView()
{
    if (!isEmpty())
        return ptr[front];
    cout << "\n Queue is Empty";
    return -1;
}
int main()
{
    queue obj(5);
    obj.insertion(10);
    obj.insertion(20);
    obj.insertion(30);
    obj.insertion(40);
    obj.insertion(50); 
    obj.deletion();obj.deletion();obj.deletion();obj.deletion();obj.deletion();obj.deletion();
    cout<<obj.frontView()<<endl;
    cout << obj.rearView() << endl;
}