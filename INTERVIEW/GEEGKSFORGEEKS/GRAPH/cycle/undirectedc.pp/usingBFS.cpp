// problem description
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


bool BFS(vector<int> adj[],int src,vector<bool> &visited)
{
    unordered_map<int,int> parent;
    queue<int> q;
    visited[src]=true;
    q.push(src);
    parent[src]=-1;
    while(1)
    {
        int currentVertex=q.front();
        q.pop();
        for(int i=0;i<adj[currentVertex].size();i++)
        {
            int nextVertex=adj[currentVertex][i];
            if(visited[nextVertex]==false)
            {
                parent[nextVertex]=currentVertex;
                // first visit the vertex then push in queue
                visited[nextVertex]=true;
                q.push(nextVertex);
            }
            else
            {
                if(parent[currentVertex]!=nextVertex)
                return true;
            }
        }
        if(q.empty()==true)
        break;
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
            if(BFS(adj,i,visited))
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