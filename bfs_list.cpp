#include <iostream>
#include "graph_list.cpp"
#include <list>
using namespace std;

void bfs_list(Graph &g, int src)
{
    int n,u;
    list<int> queue;
    bool status[g.getV_count()];
    queue.push_back(src);
    for (int i = 0; i < g.getV_count(); i++)
        status[i] = false;
    status[src] = true;
    while (!queue.empty())
    {
        n=queue.front();
        cout<<n<<" ";
        queue.pop_front();
        DynArray adjacent = g.adjacentNodes(n);
        for(int i=0;i<adjacent.count();i++){
            u=adjacent.get(i);
            if(status[u]==false){
                queue.push_back(u);
                status[u]=true;
            }
        }
    }
}

int main()
{
    Graph obj;
    obj.createGraph(5);
    bfs_list(obj, 0);
    return 0;
}