#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
    int item;
    node *next;
};

class SLL
{
private:
    node *start;

public:
    SLL();
    void insertAtStarting(int);
    void insertAtEnd(int);
    node *searchnode(int);
    void insertData(int, node *);
    void deletefirst();
    void deletelast();
    void deletespecific(node *);
};
void SLL::deletespecific(node *ptr)
{
    if (start == NULL)
        cout << "underflow\n";

    else
    {
        if (ptr)
        {
            if (start == ptr)
            {
                start = ptr->next;
                delete ptr;
            }
            else
            {

                node *t = start;
                while (t->next != NULL)
                    t->next;
                t->next = ptr->next;
                delete ptr;
            }
        }
    }
}

SLL::~SLL(){
    while(start)
        deletefirst();
}
void SLL::deletelast()
{
    node *t;
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else if (start = NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        t = start;
        while (t->next->next != NULL)
            t = t->next;
        delete t->next;
        t->next = NULL;
    }
}
void SLL::deletefirst()
{

    node *ptr;
    if (start)
    {
        ptr = start;
        start = start->next;
        delete ptr;
    }
}
void SLL::insertData(int data, node *t)
{
    node *n = new node;
    n->item = data;
    n->next = t->next;
    t->next = n;
}
void SLL::insertAtEnd(int item)
{
    node *t;
    node *n = new node;
    n->item = item;
    n->next = NULL;
    if (start == NULL)
        start = n;
    else
    {
        t = start;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}
node *SLL::searchnode(int item)
{
    node *t;
    t = start;
    while (t != NULL)
    {
        if (t->item == item)
            return t;
        t = t->next;
    }
    return NULL;
}
void SLL::insertAtStarting(int item)
{
    node *n;
    n = new node;
    n->item = item;
    n->next = start;
    start = n;
}

SLL::SLL()
{
    start = NULL;
}
int main()
{
    SLL obj;

    return 0;
}
