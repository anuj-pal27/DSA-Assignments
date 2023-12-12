#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};

class stack{
    private:
        node *top;
    public:
        stack();
        void push(int );
        int peek();
        bool isEmpty();
        void pop();
        ~stack();
        void reverseStack();
};
void stack::reverseStack(){
    node *t2,*t1;
    if(top && top->next){
        t1=NULL;
        do
        {   
            t2=top;
            top=top->next;
            t2->next=t1;
            t1=t2;
        } while (top!=NULL);
        top->next=t2;
    }
}
stack::~stack(){
    while(top)
        pop();
}
bool stack::isEmpty(){
    return top==NULL;
}
stack::stack(){
    top=NULL;
}

void stack::push(int data){
    node *n;
    n=new node;
    n->item=data;
    n->next=top;
    top=n;     
}

int stack::peek(){
    if(isEmpty()){
        cout<<"Stack is Empty UNDERFLOW\n";
        return 0;}
    return top->item;
}   
void stack::pop(){
    node *t;
    t=top;
    if(isEmpty())
    {cout<<"array is empty underflow\n";}
    else{
        cout<<peek()<<"element deleted\n";
        top=top->next;
        delete t;
    }
}

int main(){
    stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.pop();
   cout<< obj.peek();
    return 0;
}