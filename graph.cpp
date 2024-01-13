#include<iostream>

using namespace std;
class graph
{
private:
    int V_count;
    int E_count;
    int **adj;

public:
    void createGraph(int, int);
    void printGraph();
    void adjacentGraphElement(int );
    bool is_isolatedNode(int);
    ~graph();
};
graph::~graph(){
    for(int i=0;i<V_count;i++){
        delete[]adj[i];
    }
    delete adj;
}
bool graph::is_isolatedNode(int v){
    bool flag=true;
    if(v>=0 && v<V_count){
        for(int i=0;i<V_count;i++){
            if(adj[v][i]==0)
            {
                flag=false;
                break; 
            }
        }
    }
    return flag;
}
void graph::adjacentGraphElement(int v){
    if(v>=0 && v<V_count){
        for(int i=0;i<V_count;i++){
            if(adj[v][i]==1)
                cout<<endl<<"V"<<i;
        }
    }
}
void graph::createGraph(int v_no, int e_no)
{
    int u,v;
    V_count = v_no;
    E_count = e_no;
    adj = new int *[V_count];
    for (int i = 0; i < V_count; i++)
    {
        adj[i] = new int[V_count];
    }
    for(int i =0;i<V_count;i++)
        for(int j=0;j<V_count;j++)
            adj[i][j]=0;

    for(int k=0; k < E_count; k++){
        cout<<"Enter the two nodes for the graph \n";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}

void graph::printGraph(){
    cout<<endl;
    for(int i = 0 ; i<V_count;i++){
        for(int j=0;j<V_count;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    graph obj1;
    obj1.createGraph(5,6);
    obj1.printGraph();
    return 0;
}