#include<bits/stdc++.h>
using namespace std;


struct node{
    int des;
    int wt;
    node(int _des,int _wt){
        des=_des;
        wt=_wt;
    }
};


void addEdge(vector<node> graph[],int src,int des,int wt){
    graph[src].push_back(node(des,wt));
    graph[des].push_back(node(src,wt));
}


void dij(vector<node> graph[],int V)
{
    vector<int> dis(V+1,INT_MAX);
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;   // a[0]=dist    a[1]=vertex
    
    dis[0]=0;
    pq.push({0,0});
    
    while(!pq.empty())
    {
        int u=pq.top()[1];
        pq.pop();
        
        for(auto x:graph[u])
        {
            int v=x.des;
            int w=x.wt;
            
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
            
        }
        
    }
    
    for(int i=0;i<V;i++)
    cout<<dis[i]<<" ";
    
}

int main(){
    vector<node> graph[9];
    addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7);
    dij(graph,9);
    

}