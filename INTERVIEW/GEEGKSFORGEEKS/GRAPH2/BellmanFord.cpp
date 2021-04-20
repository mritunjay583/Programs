// https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0
//Bellmanford
//this algorithm can be used to detect negative weight cycle in graph
//also it finds single shrotest path if there if negative weight edge but not 
//negative weight cycle

#include<bits/stdc++.h>
using namespace std;
struct node{
    int src,des,wt;
    node(int _src,int _des,int _wt){
        src=_src;
        des=_des;
        wt=_wt;
    }
};

bool isNegativeCycle(vector<node> vt,int v /*number of vertex*/,int e/*number of edges*/){
    //preprocessing
    int dis[v]; //strores distance of all vertex from source vertex
    for(int i=0;i<v;i++){
        dis[i]=INT_MAX;
    }
    int src=0; // let 0 be the source vertex
    dis[src]=0; 

    //running this loop atmost v-1 times
    for(int i=0;i<v-1;i++){
        //relaxing all the edges 
        for(int j=0;j<vt.size();j++){

            //relaxation
            if(dis[vt[j].src]!=INT_MAX && dis[vt[j].src]+vt[j].wt<dis[vt[j].des]){
                dis[vt[j].des]=dis[vt[j].src]+vt[j].wt;
            }

        }
    }

    //if furthur more relaxation is required then it contains negative weight cyle
    for(int j=0;j<e;j++){

        if(dis[vt[j].src]!=INT_MAX && dis[vt[j].src]+vt[j].wt<dis[vt[j].des]){
            return 1;
        }

    }
    return 0;
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<node> vt;
	    for(int i=0;i<e;i++){
	        node input(1,1,1);
	        cin>>input.src>>input.des>>input.wt;
	        vt.push_back(input);
	    }
        bool res=isNegativeCycle(vt,v,e);
        if(res){
            cout<<"this graph contains negative weight cycle"<<endl;
        }  
        else{
            cout<<"this graph does not contain negative weight cycle"<<endl;
        }
	}
	return 0;
}

// sample input
//// 2
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// 3 3
// 0 1 -5 1 2 -6 2 0 -9