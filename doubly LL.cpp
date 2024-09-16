#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
}

struct node
{
    int item;
    node next;
    node prev;
};

class DLL
{
    node start;
    DLL();
    void insertAtBeg(int);
    void insertAtEnd(int);
    node *searchNode(int);
    void insertAtNode(int, node *);
    void deleteAtFirst();
    void deleteAtLast();
    void deleteAtSpecific(node *);
};
DLL::~DLL(){
    while(start)
        deleteAtFirst();
    
}
void DLL::deleteAtSpecific(node *ptr)
{
        if(ptr->prev)
            ptr->prev->next=ptr->next;
        else
            start=ptr->next;
        if(ptr->next)
            ptr->next->prev=ptr->prev;
            
        delete ptr;
        }

void DLL::deleteAtFirst()
{
    if (start)
    {
        node *t;
        t = start;
        start = start->next;
        if (t->next)
            start->prev = NULL;
        delete t;
    }
}
void DLL::deleteAtLast()
{
    node *t;
    t = start;
    if (start)
    {
        while (t->next == NULL)
            t = t->next;
        if(t->prev)
            t->prev->next = NULL;
        else
            start = NULL;
    }
    delete t;
}


node *DLL::searchNode(int data)
{
    node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        if (ptr->item == data)
            return t;
        ptr = ptr->nextl
    }

    return NULL;
}
void DLL::insertAtNode(int data, node *ptr)
{

    if (ptr)
    {
        node *n;
        n->item = data;
        n->prev = ptr;
        n->next = ptr->next;
        if (ptr->next)
            ptr->next->prev = n;
        ptr->next = n;
    }
}
void DLL::insertAtEnd(int data)
{
    node *n, *t;
    n->item = data;
    n->next = NULL;
    if (start = NULL)
    {
        n->prev = NULL;
        start = n;
    }
    else
    {
        t = start;
        while (t->next != NULL)
            t = t->next;
        n->prev = t;
        t->next = n;
    }
}
void DLL::insertAtBeg(int data)
{
    node *n;
    n->item = data;
    n->prev = NULL;
    n->next = start;
    if (start)
        start->prev = n;
    start = n;
}
}

DLL::DLL()
{
    start = NULL;
}
