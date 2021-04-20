// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.

//  https://practice.geeksforgeeks.org/problems/bipartite-graph/1

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool Helper(int G[][MAX],int V,int src,vector<bool> &visited)
{
     queue<pair<int,int> > pending;
     unordered_set<int> s[2];
     s[0].insert(src);
     pending.push(make_pair(src,0));
     while(1)
     {
         pair<int,int> temp=pending.front();
         pending.pop();
         visited[temp.first]=true;
         for(int i=0;i<V;i++)
         {
             if(G[temp.first][i]==1)
             {
                 if(i==temp.first)return false;
                 if(s[(temp.second)%2].find(i)!=s[(temp.second)%2].end())
                 {
                     return false;
                 }
                 else
                 {
                     if(visited[i]==false)
                     {
                        s[(temp.second+1)%2].insert(i);
                        pending.push(make_pair(i,temp.second+1));
                     }
                 }
             }
         }
         if(pending.empty()==true)
         break;
     }
     
     return true;
}
bool isBipartite(int G[][MAX],int V)
{
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(Helper(G,V,i,visited)==false)
            {
                return false;
            }
        }
    }
    return true;
}