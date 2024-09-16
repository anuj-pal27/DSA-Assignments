#include<iostream>
#include "array structure.cpp"
using namespace std;

class stack:private array {
    public:
    stack(int );
    stack(stack &);
    void push(int );
    int peek();
    void pop();
    ~stack();
    virtual bool isFull();
    virtual bool isEmpty();
    int getStackSize();
    void operator=(stack &);
};
bool stack::isEmpty(){
    return array::isEmpty();
}
void stack::operator=(stack &s){
    array::operator=(s);     //calling array class opertaor
}
int stack::getStackSize(){
    return getcapacity();
}
stack::stack(stack &s):array(s){

}
void reverseStack(stack &s1){
    stack s2(s1.getStackSize());

    while(!s1.isEmpty()){
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;                      //operator overloading
}
bool stack::isFull(){
    return array::isFull();
}
stack::~stack(){}
stack::stack(int cap):array(cap){}

void stack::push(int data){
    if(isFull())
        cout<<"stack is overflow";
    else
        appendElement(data);    
}
int stack::peek(){
    if(!isEmpty())
        return getElementbyIndex(countElement()-1);
    else{
        cout<<"array is empty";
    }
    return 0;
}
void stack::pop(){
if(isEmpty()){
    cout<<"stack is empty";
}
else{   
    delElement(countElement()-1);
    
}
}
// int main(){
//     stack s(5);
//     s.push(20);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(70);
//     cout<<endl<<s.peek();
//     reverseStack(s);
//     cout<<endl<<s.peek();
//     cout<<endl;
//     return 0;
// }