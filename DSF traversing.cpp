#include<iostream>
#include"stack1.cpp"
#include "graph.cpp"
// #include "DynArray_lyst9780.cpp"
using namespace std;

void dsf(graph &g,int src){
    int n,u;
    stack s(g.getV_count());
    bool status[g.getV_count()];
    for(int j=0;j<g.getV_count();j++){
        status[j]=false;
    }
    s.push(src);
    status[src]=true;
    while(!s.isEmpty()){
        n=s.peek();
        cout<<" V"<<n;
        s.pop();
        DynArray adjacent= g.adjacentNodes(n);
          for(int i=0;i<adjacent.count();i++){
            u=adjacent.get(i);
            if(status[u]==false){
                s.push(u);
                status[u]=true;
            }
        }
    }
}


int main(){
    graph g;
    g.createGraph(6,9);
    dsf(g,0);
    cout<<endl;
    return 0;
}