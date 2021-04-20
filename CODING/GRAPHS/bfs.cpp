#include<bits/stdc++.h>

using namespace std;

void printgraph(vector<vector<int> > g){
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            cout<<i<<" -> "<<g[i][j]<<endl;
        }
    }
}
void bfs(vector<vector<int> > g){
    vector<bool> visited(g.size(),false);
    queue<int> q;
    q.push(0);  // bfs from source node 0
    int source;
    while(!q.empty()){
        source=q.front();
        q.pop();
        cout<<source<<" ";
        visited[source]=true;
        for(int i=0;i<g[source].size();i++){
            if(visited[g[source][i]]==false){
            q.push(g[source][i]);
            visited[g[source][i]]=true;
            }
        }
    }
        
}
int main(){
    vector<vector<int> > g(10);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(3);
    g[2].push_back(4);
    g[5].push_back(6);
    g[5].push_back(7);
    g[7].push_back(9);
    g[6].push_back(5);
    g[7].push_back(8);
    printgraph(g);
    bfs(g);
}   