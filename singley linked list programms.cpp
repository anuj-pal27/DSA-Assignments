#include<stdio.h>
using namespace std;

struct node
{
    /* data */
    int item;
    node *next;
};


class SLL{
    public:
    node *start;

    void count();
    void reverselist();
    void middlenode();
    void cycle();
    void lengthcycle();
    void sortlist();
};

void SLL::count(){
    node *t;
    t=start;
    int count=1;
    while(t->next!=NULL){
        t=t->next;
        count+=1;
    }
    cout<<count;
}

void SLL::reverselist(){
    node *t1,*t2,*t3;
    t1=start;
    t2=t1->next;
    t3=t2->next;
    t1->next=NULL;
    while(t3!=NULL){
        t2->next=t1;
        t1=t2;
        t2=t3;
        t3=t3->next;
    }
    start=t2;

}

void SLL::middlenode(){
    node *t1,*t2;
    t1=start;
    t2=start;
    while(t2->next!=NULL || t2!=NULL){
        t1=t1->next;
        t2=t1->next;
    }
}
void SLL::cycle(){
    node *t1,*t2;
    t1=start;
    t2=start;
    while(t1!=t2)
    {
        t2=t2->next->next;
        t1=t1->next;
    }
    if(t1==t2)
        cout<<"yes it is cylce";
    else
        cout<<"not cycle";
}

void SLL::lengthcycle(){
    node *t1,*t2;
    int count=1;
    void cycle();
    t1=t1->next;
    while(t1!=t2){
        t=t->next;
        count+=1;        
    }
    cout<<count;

}
void SLL::sortlist(){
    node *t1,*t2,*temp;
    t1=start;
    t2=start;
    while(t2!=NULL){
        if(t2->item < t1->item){
            temp=t2->item;
            t2->item=t1->item;
            t1->item=temp;
        }
    t2=t2->next;
    t1=t1->next;
    }
}

