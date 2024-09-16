#include <iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
private:
    node *last;

public:
    CLL();
    void insertAtBeg(int);
    void insertAtEnd(int);
    node *searchnode(int);
    void insertAtNode(node *, int);
    void deletefirst();
    void deletelast();
    void deleteNode(node *);
};
 CLL::CLL()
{
    last = NULL;
}

void CLL::insertAtBeg(int data)
{
    node *n = new node;
    n->item = data;
    if (last)
    {
        n->next = last->next;
        last->next = n;
    }
    else
        n->next = n;
    last = n;
}

void CLL::insertAtEnd(int data)
{
    node *n = new node;
    n->item = data;
    if (last)
    {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}

node CLL::searchnode(int data)
{
    if (last == NULL)
        cout << "Node not exist";
    else
    {
        while (last->next != last)
            if (last->next->item = data)
                return last->next;
            else
                last->next = last->next->next;
    }
    return NULL;
}

void CLL::insertAtNode(node *t, int data)
{
    if (last)
    {
        node *n = new node;
        n->item = data;
        n->next = t->next;
        t->next = n;
        if (t == last)
            last = n;
    }
}

void CLL::deletefirst()
{

    node *t;
    t = last->next;
    if (last->next == last)
    {
        last = NULL;
    }
    else
    {
        last->next = t->next;
        delete t;
    }
}

void CLL::deletelast()
{
    node *t;
    if (last)
    {
        node* t;
        t= last;
        while(t->next!=last)
            t=t->next;
        if(t==last)
        {
            delete last;
            last=NULL;
        }
        else{
            t->next=last->next;
            delete last;
            last = t;
        }
    }
}

void CLL::deleteNode(node *temp){
    if(temp){
        node *t;
        t=last->next;
        while(t->next!=temp)
            t=t->next;
        t->next=temp->next;
        if(t==temp)
            last=NULL;
        else if(temp==last)
            last=t;
        delete temp;
    }
}
