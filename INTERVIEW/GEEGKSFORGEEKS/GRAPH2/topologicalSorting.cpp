#include<bits/stdc++.h>
#include"graph.h"


void helper(vector<int>* gra,int n,vector<bool> &visited,int indegree[],vector<int> &res){
    
    int flag=0;
    for(int i=0;i<n;i++){

        //recurr for all vertices which has not visited yet and indegree =0
        if(indegree[i]==0 && visited[i]==false){
            //mark visited
            visited[i]=true;
            //push the vertex in result
            res.push_back(i);

            //reduce indegree of vertices adjacent to i
            for(int v=0;v<gra[i].size();v++){
                indegree[gra[i][v]]--;
            }

            helper(gra,n,visited,indegree,res);

            //backtrack
            visited[i]=false;
            res.pop_back();
            for(int v=0;v<gra[i].size();v++){
                indegree[gra[i][v]]++;
            }
            flag=1;
        }
    }
    //if all the vertices has visited 
    if(flag==0){
            for(auto x:res){
                cout<<x<<" ";
            }
            cout<<endl;
    }
}

// https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/
void allTopologicalSorts(vector<int>* gra,int n){
    
    vector<bool> visited(n,false);

    //calculate indegree of all the vertices
    int indegree[n]={0};   // array to store indegree of each vertex

    for(int u=0;u<n;u++){
        for(int v=0;v<gra[u].size();v++){
            indegree[gra[u][v]]++;
        }
    }

    vector<int> res;
    cout<<"all topological sorts of the graph is: -"<<endl;
    helper(gra,n,visited,indegree,res);

}


/////////////////////////////////////////////////////////////////////////////////
void DFS(vector<int> *g,int n,int  src,vector<bool> &visited,stack<int> &st){
    if(visited[src]==true){
        return;
    }
    visited[src]=true;

    for(int v=0;v<g[src].size();v++){
        if(visited[g[src][v]]==false){
            DFS(g,n,g[src][v],visited,st);
        }
    }
    st.push(src);
    
}

void topologicalSort_usingDFS(vector<int> *g,int n){
    
    stack<int> st; //this stack will store topological order in
                                        //reverse order
    vector<bool> visited(n,false);

    for(int i=0;i<n;i++){
        if(visited[i]==false){
            DFS(g,n,i,visited,st);
        }
    }

    cout<<"one of the topological order of the given graph is :-"<<endl;
    while(st.empty()==false){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

}
////////////////////////////////////////////////////////////////////////////////

void topologicalSort_usingKhansAlgorithm(vector<int>* g,int n){
    //calculate indegree of all the vertices
    int indegree[n]={0};   // array to store indegree of each vertex

    for(int u=0;u<n;u++){
        for(int v=0;v<g[u].size();v++){
            indegree[g[u][v]]++;
        }
    }

    //main Algorithm starts from here
    queue<int> q;
    int totalVisitedVertex=0;
    vector<int> topologicalOrder;

    //push all the vertex in queue which has indegree 0
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(q.empty()==false){
        int u=q.front();
        q.pop();
        totalVisitedVertex++;  //increment the visiting count
        topologicalOrder.push_back(u); // adding vertex in topological array

        for(int v=0;v<g[u].size();v++){
            // decrementing the count of indegree of adjacent vertex of u
            indegree[g[u][v]]--;

            // pushing all the vertex adjacent to u has indegree 0
            if(indegree[g[u][v]]==0){
                q.push(g[u][v]);
            }
        }
    }

    if(totalVisitedVertex==n){
        cout<<"one of the topological order of the given graph is :-"<<endl;
        for(auto x:topologicalOrder){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"topological ordering is not possible because it is not DAG"<<endl;
        cout<<"this Directed Graph contains cycle"<<endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////

int main(){
    string inputFile="input.txt";
    graph g;
    pair<vector<int>*,int> data=g.getGraph(inputFile);
    int n=data.second;
    vector<int> *gra=data.first;

    topologicalSort_usingKhansAlgorithm(gra,n);
    topologicalSort_usingDFS(gra,n);
    allTopologicalSorts(gra,n);
}