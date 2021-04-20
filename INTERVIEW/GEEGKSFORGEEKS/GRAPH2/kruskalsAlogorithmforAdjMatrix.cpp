// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program is 
// for adjacency matrix representation of the graph 
#include <bits/stdc++.h> 
using namespace std; 

const int V=5;

pair<int,int> getMin(int graph[V][V],set<pair<int,int> > &includedVertex){
    int x=INT_MAX;
    int a;
    int b;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]!=0 && includedVertex.count(make_pair(i,j))<=0 && includedVertex.count(make_pair(j,i))<=0){
                if(x>graph[i][j]){
                    x=graph[i][j];
                    a=i;
                    b=j;
                }
            }
        }
    }
    return make_pair(a,b);
}
bool notSameParent(int x,int y,vector<int> &parent){
    if(parent[x]!=parent[y]){
        return true;
    }
    return false;
}

void primsMST(int graph[V][V]){
    set<pair<int,int>> includedVertex;
    vector<int> parent(V,0);   //you can use union find approach to solve problem quickly
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
    }

    int i=0;
    cout<<"edges"<<" "<<"weights"<<endl;
    while(i<V-1){
        pair<int,int> x=getMin(graph,includedVertex);
        if(notSameParent(x.first,x.second,parent)){
            parent[x.second]=parent[x.first];
            includedVertex.insert(x);
            cout<<x.first<<" - "<<x.second<<"   "<<graph[x.first][x.second]<<endl;
            i++;
        }
    }
}

// Driver code 
int main() 
{ 
	/* Let us create the following graph 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| / \ | 
	(3)-------(4) 
			9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	// Print the solution 
	primsMST(graph); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
