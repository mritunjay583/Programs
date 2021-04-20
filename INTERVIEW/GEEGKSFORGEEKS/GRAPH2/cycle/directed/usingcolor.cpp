//for problem description and what is input output
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


#include <bits/stdc++.h>
using namespace std;
enum Color {WHITE,GERY,BLACK};
bool DFS(vector<int> adj[],int src,vector<Color> &color)
{
    color[src]=BLACK;
    for(int i=0;i<adj[src].size();i++)
    {
        if(color[adj[src][i]]==WHITE)
        {
            color[adj[src][i]]=GERY;
            if(DFS(adj,adj[src][i],color))
            return true;
        }
        else
        {
            if(color[adj[src][i]]==GERY)
            {
                return true;
            }
        }
        
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<Color> color; 
    for(int i=0;i<V;i++)
    {
        color[i]=WHITE;
    }
    for(int i=0;i<V;i++)
    {
        if(color[i]==WHITE)
        {
            if(DFS(adj,i,color))
            return true;
        }
    }
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends