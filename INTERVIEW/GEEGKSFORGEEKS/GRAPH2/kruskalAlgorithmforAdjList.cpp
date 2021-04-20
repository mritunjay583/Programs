// C / C++ program for Prim's MST for adjacency list representation of graph 
// https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/

#include<bits/stdc++.h>

using namespace std;

struct node{
    int src;
    int des;
    int wt;
    node(int _src,int _des,int _wt){
        src=_src;
        des=_des;
        wt=_wt;
    }
};


int root(int x,int parent[]){
    while(x!=parent[x]){
        x=parent[x];
        parent[x]=parent[parent[x]]; //path compression
    }
    return x; 
}

bool find(int x,int y,int parent[]){
    if(root(x,parent)==root(y,parent)){
        return false;
    }
    return true;
}

void do_union(int x,int y,int parent[]){
    int root_x=root(x,parent);
    int root_y=root(y,parent);
    parent[root_y]=parent[root_x];
}

void primesMST(vector<node> &graph,int V){
    // min heap priority queue
    auto cmp=[](node x,node y)->bool{
        return x.wt>y.wt;
    };
    priority_queue<node,vector<node>,decltype(cmp)> q(cmp);

    //adding edges to min heap
    for(auto x:graph){
        q.push(x);
    }

    //parent array to get the knowledge which vertex has included or not
    int parent[V];
    for(int i=0;i<V;i++)parent[i]=i;

    //main MST Algorithm
    int i=0;
    while(i<V-1){
        node cur_edge=q.top();
        q.pop();
        if(find(cur_edge.src,cur_edge.des,parent)) // cheking ig parent of two adjacent are
        {                                          //same or not to know they will form cycle or not
            do_union(cur_edge.src,cur_edge.des,parent);//including pair of edges in MST
                                                      //which are not forming cycle
            cout<<cur_edge.src<<" "<<cur_edge.des<<" "<<cur_edge.wt<<endl;
            i++;
        }
    }

}

int main()
{ 
	// Let us create the graph given in above fugure 
	int V = 9; 
    vector<node> graph;
    graph.push_back(node(0, 1, 4)); 
    graph.push_back(node(0, 7, 8)); 
    graph.push_back(node(1, 2, 8)); 
    graph.push_back(node(1, 7, 11)); 
    graph.push_back(node(2, 3, 7)); 
    graph.push_back(node(2, 8, 2)); 
    graph.push_back(node(2, 5, 4)); 
    graph.push_back(node(3, 4, 9)); 
    graph.push_back(node(3, 5, 14)); 
    graph.push_back(node(4, 5, 10)); 
    graph.push_back(node(5, 6, 2)); 
    graph.push_back(node(6, 7, 1)); 
    graph.push_back(node(6, 8, 6)); 
    graph.push_back(node(7, 8, 7)); 

    primesMST(graph,V);

	return 0; 
} 
