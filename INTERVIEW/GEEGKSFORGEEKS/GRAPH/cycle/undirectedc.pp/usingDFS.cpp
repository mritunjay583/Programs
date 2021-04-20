// problem description
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


bool DFS(vector<int> adj[],int src,int parent,vector<bool> &visited)
{
    visited[src]=true;
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]]==false)
        {

            if(DFS(adj,adj[src][i],src,visited))
            return true;

        }
        else
        {
            if(adj[src][i]!=parent)
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int>  adj[],int V) 
{
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(DFS(adj,i,-1,visited))
            return true;
        }
    }
    return false;
} 
// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends