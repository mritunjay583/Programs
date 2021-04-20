
// problem description
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include<bits/stdc++.h>

using namespace std;


int root(int x,int par[])
{
    while(x!=par[x])
    {
        par[x]=par[par[x]];  //path compression
        x=par[x];
    }
    return x;
}

void dounion(int x,int y,int par[])
{
    int root_x=root(x,par);
    int root_y=root(y,par);
    par[root_y]=root_x;
}
bool isCyclic(vector<int>  adj[],int V) 
{
    map<int,unordered_set<int> > child_multiparent;
    
    //initaillizing parent array for union find
    int par[V];
    for(int i=0;i<V;i++)
    {
        par[i]=i;
    }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int x=i;
            int y=adj[i][j];

            if(x==y)   // for self loop
            return true;

            if(root(x,par)!=root(y,par))
            {
                child_multiparent[y].insert(x);   // storing parent of adj[i][j] it may have multiple
                                                 // in future so dont try to update parent just store
                                                // all parent
                                                
                dounion(x,y,par); // doing union of two vertices
            }
            else if(child_multiparent[i].find(adj[i][j])==child_multiparent[i].end())
            {
                return true;
            
            }
            
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