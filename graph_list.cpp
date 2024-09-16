#include <iostream>
#include <stdio.h>
#include "DynArray_lyst9780.cpp"

using namespace std;

struct node
{
    int vertex;
    node *next;
    int item;
};
class adjList
{
private:
    node *start;
    int V_data;

public:
    adjList();
    node* start_node();
    void add_node(int, int);
    void set_vertex(int);
    void removeAdjList();
    void printAdjList();
    ~adjList();
};
node* adjList::start_node(){
    return start;
}
class Graph
{
private:
    int V_count;
    adjList *arr;

public:
    Graph();
    int getV_count();
    DynArray& adjacentNodes(int);
    void createGraph(int);
    void printGraph();
    ~Graph();
};
DynArray& Graph::adjacentNodes(int n){
    DynArray *p=new DynArray(1);
        node *t;
        t=this->arr[n].start_node();
        while (t)
        {
            p->append(t->vertex);
            t=t->next;
        }
        return *p;
}

int Graph::getV_count(){
    return V_count;
}
void Graph::printGraph()
{
    for (int i = 0; i < V_count; i++)
    {
        cout << endl
             << " " << i << " --->";
        arr[i].printAdjList();
    }
}
void adjList::printAdjList()
{
    node *t;
    t = start;
    while (t)
    {
        cout << " (vertex--> " << t->vertex << ",item: " << t->item << ") ";
        t = t->next;
    }
}
adjList::~adjList()
{
    while (start)
        removeAdjList();
}
void adjList::removeAdjList()
{
    node *r;
    if (start)
    {
        r = start;
        start = start->next;
        delete r;
    }
}
void adjList::set_vertex(int v)
{
    V_data = v;
}
Graph::~Graph()
{
    delete[] arr;
}
void adjList::add_node(int v, int data)
{
    node *n = new node;
    n->vertex = v;
    n->item = data;
    n->next = start;
    start = n;
}

void Graph::createGraph(int vno)
{
    int n, v, data;
    V_count = vno;
    arr = new adjList[vno];
    for (int i = 0; i < V_count; i++)
    {
        arr[i].set_vertex(i);
        cout << "\n how many adjacent of V" << i << ":";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cout << "\nEnter the Vertex";
            cin >> v;
            // cout << "\n Enter the data";
            // cin >> data;
            data=10;
            arr[i].add_node(v, data);
        }
    }
}
adjList::adjList()
{
    start = NULL;
}

Graph::Graph()
{
    V_count = 0;
    arr = NULL;
}

// int main(){
//     Graph obj;
//     obj.createGraph(5);
//     obj.printGraph();
// }