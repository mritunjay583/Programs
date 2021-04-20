#include<bits/stdc++.h>

using namespace std;

void printgraph(vector<vector<int> > g){
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            cout<<i<<" -> "<<g[i][j]<<endl;
        }
    }
}
void dfs(vector<vector<int> > g,int source,int neighbour,vector<int> &color){
    if(color[neighbour]!=-1){
        return;
    }
    color[neighbour]=source;
    for(int i=0;i<g[neighbour].size();i++){
        dfs(g,source,g[neighbour][i],color);
    }
}

void connected_components(vector<vector<int> > g){
    vector<int> color(g.size(),-1);
    int cnt=0;
    for(int i=0;i<color.size();i++){
        if(color[i]==-1){
        dfs(g,i,i,color);
        cnt++;
        }
    }

    for(int i=0;i<color.size();i++){
        cout<<i<<" -->> "<<color[i]<<endl;
    }
    cout<<"number_of_connected_componenets are : "<<cnt;
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
    g[8].push_back(8);
    printgraph(g);
    connected_components(g);
}