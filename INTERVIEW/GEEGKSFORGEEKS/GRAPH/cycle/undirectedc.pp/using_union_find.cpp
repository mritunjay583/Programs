// problem description
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include<bits/stdc++.h>

using namespace std;



bool isCyclic(vector<int>  adj[],int V) 
{
    map<int,unordered_set<int> > child_multiparent;    // there may be condition that a node 
                                                      //will have multiple parent 
    int par[V];        //parent array for union find algorithm  
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

            if(par[x]!=par[y])
            {
                int par_x=par[x];
                int par_y=par[y];
                
                child_multiparent[y].insert(x);

                for(int i=0;i<V;i++)
                {
                    if(par[i]==par_y)
                    par[i]=par_x;
                }
                
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