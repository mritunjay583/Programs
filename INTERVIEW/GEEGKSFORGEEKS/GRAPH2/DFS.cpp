#include<bits/stdc++.h>
#include"graph.h"

struct node{
    int start;
    int finish;
    int parent;
    node(){
        parent=-1;
        start=-1;
        finish=-1;
    }
};

void DFS(vector<int>* g,int src,vector<bool> &visited,int &time,vector<node> &props){
    if(visited[src]==true){
        return;
    }
    props[src].start=time++;
    visited[src]=true;
    for(int i=0;i<g[src].size();i++){
        if(visited[g[src][i]]==false){
            props[g[src][i]].parent=src;
            DFS(g,g[src][i],visited,time,props);
        }
    }
    props[src].finish=time++;
}

int main(){
    string inputFile="input.txt";
    graph g;
    pair<vector<int>*,int> data=g.getGraph(inputFile);
    int totalVertex=data.second;
    vector<int> *graph=data.first;
    
    int time=0;
    vector<node> props(totalVertex);
    vector<bool> visited(totalVertex,false);

    for(int i=0;i<totalVertex;i++){
        if(visited[i]==false){
            DFS(graph,i,visited,time,props);
        }
    }

    cout<<"---------------"<<endl;
    for(int i=0;i<props.size();i++){
        cout<<i<<" : "
            <<props[i].start<<" "
            <<props[i].finish<<" "
            <<props[i].parent<<endl;
    }
}