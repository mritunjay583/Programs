#include<bits/stdc++.h>

using namespace std;

void print(int **graph,int n,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(graph[sv][i]==true)
        {
            if(visited[i]==false)
            {
                print(graph,n,i,visited);
            }
        }
    }
    return;
}

int main()
{
    int n,e;
    cin>>n>>e;
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }
    int src,des;
    for(int i=0;i<e;i++)
    {
        cin>>src>>des;
        graph[src][des]=1;
        graph[des][src]=1;
    }

    bool *visited=new bool[n]; // list to keep track of visited vertex
    for(int i=0;i<n;i++)
    visited[i]=false;
    
    print(graph,n,0,visited); // printing all vertices //DFS
    
    /// freeing memory
    for(int i=0;i<n;i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] visited;
}