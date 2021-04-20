#include<bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> x,pair<int,int> y){
        return x.second>y.second;
    }
};

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dis(V,INT_MAX);
    dis[src]=0; //first initialize distance of source node is 0
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> q;  // node distance
    q.push(make_pair(src,0)); //push src in queue
    while(q.empty()==false){
        pair<int,int> t=q.top();q.pop();
        for(int i=0;i<V;i++){ // for each vertex from source relax all vertex
            if(g[t.first][i]!=0){ //to tacle self loop
                if(t.second+g[t.first][i]<dis[i]){ //main conditiion of relaxation
                    dis[i]=t.second+g[t.first][i];
                        q.push(make_pair(i,dis[i]));
                }
            }
        }
    }
    return dis;
}

int main()
{
        int V=9;
        vector<vector<int>> g{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
        int src=0;
        vector <int> res = dijkstra(g, src, V);
        for(auto x:res)
            cout<<x<<" ";
        cout<<endl;
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
