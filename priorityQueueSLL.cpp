#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int item;
    int prno;
    node *next;
};

class priorityQueue{
    private:
        node *start;
    public:
        priorityQueue();
        void inserting(int ,int );
        bool isEmpty();
        void deleting();
        int getElement();
        int getprno();
        ~priorityQueue();
};
priorityQueue::~priorityQueue(){
    while(start)
        deleting();
}
int priorityQueue::getprno(){
    if(isEmpty()){
        cout<<"UNDERFLOW \n";
        return 0;
    }
    return start->prno;
}
int priorityQueue::getElement(){
    if(isEmpty()){
        cout<<"UNDERFLOW\n";
        return -1;
    }
    return start->item;
}
void priorityQueue::deleting(){
    node *t;
    if(isEmpty()){
        cout<<"Queue is Empty UNDERFLOW\n";
        return ;
    }
    t=start;
    start=start->next;
    delete t;
    
}
bool priorityQueue::isEmpty(){
    return start==NULL;
}
priorityQueue::priorityQueue(){
    start=NULL;
}
void priorityQueue::inserting(int num,int data){
    node *t;
    node *n=new node;
    n->item=data;
    n->prno=num;
    if(start==NULL){
       n->next=NULL;
       start=n;
    }
    else{
        if(start->prno < n->prno){
            n->next=start;
            start=n;
        }
        else{
            t=start;
            while(t->next!=NULL){
                if(t->next->prno >= n->prno){
                    t=t->next;
                }
                else{
                    break;
                }
                n->next=t->next;
                t->next=n;
            }
        }
    }

}