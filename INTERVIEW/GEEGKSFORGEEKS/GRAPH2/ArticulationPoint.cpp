// main problem
// https://practice.geeksforgeeks.org/problems/doctor-strange/0

// main concept
// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[], int u, int low[], int desc[], int visited[], int &time, int parent[], bool ap[])
{
    if (visited[u] == 1)
    {
        return;
    }
    visited[u] = 1;
    int children = 0;
    low[u] = desc[u] = ++time;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (visited[v] == 0)
        {
            children++;
            parent[v] = u;
            DFS(g, v, low, desc, visited, time, parent, ap);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u] = min(low[v], low[u]);

            // u is an articulation point in following cases
            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == -1 && children > 1)
            {
                ap[u] = true;
            }

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != -1 && low[v] >= desc[u])
            {
                ap[u] = true;
            }
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

void articulationPoints(vector<int> g[], int n)
{
    int low[n] = {0};
    int disc[n] = {0};    //to store discovery point of any vertex
    int visited[n] = {0}; //mark nodes
    int parent[n] = {0};  //storing parent of each node in DFS tree
    bool ap[n];           // to store articulation point
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1; //initially all nodes will have parent NULL
        ap[i] = false;  //initially there is no articulation point
    }
    int time = 0; // time
    DFS(g, 0, low, disc, visited, time, parent, ap);

    // Now ap[] contains articulation points, print them
    cout << "Articulation points are : ";
    for (int i = 0; i < n; i++)
        if (ap[i] == true)
            cout << i << " ,";
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
            g[p - 1].push_back(q - 1);
            g[q - 1].push_back(p - 1);
        }

        articulationPoints(g, n); //METHOD TO FIND ARTICULAION POINTS
    }
    return 0;
}

//sample input
// 1
// 5 5
// 1 2
// 1 3
// 3 2
// 3 4
// 5 4