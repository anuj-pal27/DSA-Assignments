#include <iostream>
using namespace std;

class graph
{
private:
    int V_count;
    int E_count;
    int **adj;

public:
    graph();
    int getV_count();
    void createGraph(int, int);
    void prim();
    ~graph();
};
graph::graph()
{
    adj = NULL;
}
void graph::prim()
{
    int near[V_count], k = 65536, u, v;
    int t[2][V_count - 2];
    for (int i = 1; i < V_count; i++)
    {
        for (int j = i; j < V_count; j++)
        {
            if (k > adj[i][j])
            {
                k = adj[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (int i = 1; i < V_count; i++)
    {
        if (near[i] != 0)
        {
            if (adj[i][u] < adj[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    for (int i = 1; i < V_count - 2; i++)
    {
        int min = 65536;
        for (int j = 1; j < V_count; j++)
        {
            if (near[j] != 0 && adj[j][near[j]] < min)
            {
                k = j;
                min = adj[j][near[j]];
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (int j = 1; j < V_count; j++)
        {
            if (near[j] != 0 && adj[j][k] < adj[j][near[j]])
                near[j] = k;
        }
    }
    for (int i = 0; i < V_count - 2; i++)
    {
        cout << "(" << t[0][i] << "," << t[1][i] << ")" << endl;
    }
}
void graph::createGraph(int v_no, int e_no)
{
    int u, v, data;
    V_count = v_no;
    E_count = e_no;
    adj = new int *[V_count];
    for (int i = 0; i < V_count; i++)
    {
        adj[i] = new int[V_count];
    }
    for (int i = 0; i < V_count; i++)
        for (int j = 0; j < V_count; j++)
            adj[i][j] = 65536;

    for (int k = 1; k <= E_count; k++)
    {
        cout << "\nEnter the two nodes for the graph ";
        cin >> u >> v;
        cout << "\n Enter the weighted of V" << u << " V" << v << " ";
        cin >> data;
        adj[u][v] = data;
        adj[v][u] = data;
    }
}
int graph::getV_count()
{
    return V_count;
}
graph::~graph()
{
    for (int i = 0; i < V_count; i++)
    {
        delete[] adj[i];
    }
    delete adj;
}
int main()
{
    graph obj;
    obj.createGraph(8, 9);
    obj.prim();
}