#include<iostream>
#include "graph.cpp"
#include "queueArray.cpp"

using namespace std;

void bsf(graph &g,int src){
    int n,u,i;
    bool status[g.getV_count()];
     for(int j=0;j<g.getV_count();j++){
        status[j]=false;
    }
    queue Q(g.getV_count());
    Q.insertion(src);
    status[src]=true;

    while (!Q.isEmpty())
    {
        n=Q.frontView();
        cout<<" V"<<n;
        Q.deletion();
        DynArray adjacent = g.adjacentNodes(n);
        for(i=0;i<adjacent.count();i++){
            u=adjacent.get(i);
            if(status[u]==false){
                Q.insertion(u);
                status[u]=true;
            }
        }
        
    }
    
}

int main(){
    graph g;
    g.createGraph(6,9);
    bsf(g,0);
    cout<<endl;
    return 0;
}