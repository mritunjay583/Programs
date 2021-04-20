//for problem description and what is input output
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


#include <bits/stdc++.h>
using namespace std;

bool isAncesstor(int nextVertex,unordered_map<int,int> parent,int currentVertex)
{
    while(1)
    {
        currentVertex=parent[currentVertex]; // finding parent of currentVertex

        if(nextVertex=currentVertex)  // if currentVertex and nextVertex are same then
        return true;                    //nextVertex is Ancesstor of currentVertex
        
        if(currentVertex==-1)  // loop terminating condition
        {
            break;
        }
    }
    return false;
}
bool BFS(vector<int> adj[],int src,vector<bool> &visited)
{
    unordered_map<int,int> parent;   // store parents of current node
    queue<int> q;  // queue to implement bfs
    q.push(src);  // putting source vertex in queue
    parent[src]=-1; // parent of source vertex is -1
    
    while(1)
    {
        int currentVertex=q.front();
        q.pop();
        visited[currentVertex]=true;  // visiting current vertex

        for(int i=0;i<adj[currentVertex].size();i++)
        {
            int nextVertex=adj[currentVertex][i];

            if(nextVertex==currentVertex)   // handling condition of self loop 
            return true;

            if(visited[nextVertex]==false)
            {
                parent[nextVertex]=currentVertex;  // makeing currentVertex ,parent of nextVertex
                q.push(nextVertex);
            }
            else
            {
                if(isAncesstor(nextVertex,parent,currentVertex)) // if nextVertex is already visited
                {                                             // then checking if nextVertex is an
                    return true;                              // ancestor of current vertex
                }
            }
        }
        if(q.empty()==true)
        break;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(BFS(adj,i,visited))
            {
                return true;
            }
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