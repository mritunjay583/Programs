#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > root;
vector<int> height;
vector<int> parent;

void DFS(int cur,int cur_height,vector<bool> &visited){
    if(visited[cur]==true){
        return;
    }
    visited[cur]=true;
    height[cur]=cur_height;
    for(auto u:root[cur]){
        if(visited[u]==false){
            parent[u]=cur;
            DFS(u,cur_height+1,visited);
        }
    }
}

void buildTree(int n){
    int u,v;
    while(true){
        cin>>u>>v;
        if(u==-1){
            break;
        }
        root[u].push_back(v);
    }
    vector<bool> visited(n+1,false);
    DFS(1,0,visited);
    // for(int i=1;i<n+1;i++)cout<<"("<<i<<" , "<<height[i]<<") ";cout<<endl;
    // for(int i=1;i<n+1;i++)cout<<"("<<i<<" , "<<parent[i]<<") ";cout<<endl;
}


//this algorithm takes O(n) times
void LCA1(int u,int v){
    //uplift each node one step up if its height is greater
    //and repeat this work untill the meet at some node
    while(u!=v){
        if(height[u]>=height[v]){
            u=parent[u];
        }else{
            v=parent[v];
        }
    }
    cout<<u<<endl;
}
int main(){
    int n;
    cin>>n;
    root.resize(n+1);
    height.resize(n+1,INT_MIN);
    parent.resize(n+1,-1);
    buildTree(n);
    LCA1(4,6);
    
}
