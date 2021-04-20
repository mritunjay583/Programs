// main concept
// https://www.geeksforgeeks.org/bridge-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[], int u, int low[], int desc[], int visited[], int &time, int parent[])
{
    if (visited[u] == 1)
    {
        return;
    }
    visited[u] = 1;
    low[u] = desc[u] = ++time;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (visited[v] == 0)
        {
            parent[v] = u;
            DFS(g, v, low, desc, visited, time, parent);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[v], low[u]);

            if(low[v]>desc[u])
                cout<<u+1<<" "<<v+1<<endl;
        }
        else
        {
            // Update low value of u for parent function calls.
            if (v != parent[u])
            {
                low[u] = min(low[u], desc[v]);
            }
        }
    }
}

void bridges(vector<int> g[], int n)
{
    int low[n] = {0};
    int disc[n] = {0};    //to store discovery point of any vertex
    int visited[n] = {0}; //mark nodes
    int parent[n] = {0};  //storing parent of each node in DFS tree
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1; //initially all nodes will have parent NULL
    }
    int time = 0; // time
    cout<<"BRIDGES : ";
    DFS(g, 0, low, disc, visited, time, parent);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> g[n];
        for (int i = 0; i < m; i++)
        {
            int p, q;
            cin >> p >> q;
            g[p-1].push_back(q-1);
            g[q-1].push_back(p-1);
        }

        bridges(g, n); //METHOD TO FIND ARTICULAION POINTS
    }
    return 0;
}

//sample input
// 1
// 5 5
// 1 2
// 1 3
// 3 2
// 1 4
// 4 5

