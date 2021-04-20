//for problem description and what is input output
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>

using namespace std;

bool DFS(vector<int> adj[],int src,vector<bool> &visited,vector<bool> &ancestorsOfCurrentVertex)
{
    
    if(visited[src]==true && ancestorsOfCurrentVertex[src]==true)

    return true;
    
    visited[src]=true;  // visiting current vertex
    ancestorsOfCurrentVertex[src]=true;   // adding in recursion stack
    // getting all next vetices which are not yet visited
    for(int i=0;i<adj[src].size();i++)
    {
        if(DFS(adj,adj[src][i],visited,ancestorsOfCurrentVertex))
            return true;
    }
    ancestorsOfCurrentVertex[src]=false;   // removing from recursion stack
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);
    vector<bool> ancestorsOfCurrentVertex(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(DFS(adj,i,visited,ancestorsOfCurrentVertex))
            {
                return true;
            }
        }
    }
    return false;
}

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
	    
	    if(isCyclic(v, adj))
        {
            cout<<"cycle found"<<endl;
        }
        else
        {
            cout<<"cycle not found"<<endl;
        }
        
	    
	}
	
	return 0;
} 