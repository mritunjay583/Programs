// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program is 
// for adjacency matrix representation of the graph 
#include <bits/stdc++.h> 
using namespace std; 

const int V=5;

struct cmp{
    bool operator()(pair<int,int> p,pair<int,int> q){
        return p.first>q.first;
    }
};

void printMST(vector<int> parent,vector<int> key,int graph[V][V]){
    cout<<"edge     weight"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"      "<<graph[parent[i]][i]<<endl;
    }
}

void primsMST(int graph[V][V]) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp > pq;  ///priority queue to store pair of distance,vertex
    
    vector<bool> inMST(V,false);
    vector<int> parent(V,-1);
    vector<int> key(V,INT_MAX); //to store weight of vertex
    key[0]=0; //weight of source vertex is 0

    pq.push(make_pair(0,0));
    int k=0;
    while(!pq.empty()){
        int t=pq.top().second;pq.pop();
        inMST[t]=true;
        k++;
        for(int i=0;i<V;i++){
            if(graph[t][i]!=0 && inMST[i]==false && graph[t][i]<key[i]){
                key[i]=graph[t][i];
                pq.push(make_pair(graph[t][i],i));
                parent[i]=t;
            }
        }
    }
    printMST(parent,key,graph);
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
