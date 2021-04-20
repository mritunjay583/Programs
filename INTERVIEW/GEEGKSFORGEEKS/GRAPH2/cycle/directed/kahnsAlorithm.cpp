//for problem description and what is input output
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


#include <bits/stdc++.h>
using namespace std;


bool isCyclic(int V, vector<int> adj[])
{
    int indegree[V]={0}; // this array will store indegree of each vertex
    
    for(int i=0;i<V;i++)                      // calculating indegree of each vertex
    {
        for(int j=0;j<adj[i].size();j++)
        {
            indegree[adj[i][j]]++;
        }
    }

    int cnt=0;  /// initially count is 0
    queue<int> q; 

    for(int i=0;i<V;i++)  //pushing all vertices in queue who has indegree 0
    {
        if(indegree[i]==0)
        q.push(i);
    }

    while(q.empty()==false)
    {
        int temp=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<adj[temp].size();i++)
        {
            indegree[adj[temp][i]]--;
            if(indegree[adj[temp][i]]==0)
            q.push(adj[temp][i]);
        }
        
    }
    if(cnt<V)
    return true;
    else
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