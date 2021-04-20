// https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(array<int,3> p,array<int,3> q){
        return p[2]>q[2];
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > v(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>v[i][j];
            }
        }

        vector<vector<int > > dis(n,vector<int>(n,INT_MAX));  //distance matrix for dijkastra's algorithm
        dis[0][0]=v[0][0]; //initialize source vertex
        priority_queue<array<int,3>,vector<array<int,3> >,cmp> pq;  //priority queue
        vector<vector<int> > dir{{1,0},{0,1},{-1,0},{0,-1}};  //to move in different directions
        pq.push({0,0,dis[0][0]});  
        while(pq.size()>0){
            array<int,3> t=pq.top();pq.pop();
            for(int i=0;i<dir.size();i++){
                int x=t[0]+dir[i][0];
                int y=t[1]+dir[i][1];
                if(x>=0 && x<n && y>=0 && y<n && (t[2]+v[x][y]<dis[x][y])){   //relaxation
                    dis[x][y]=t[2]+v[x][y];
                    pq.push({x,y,dis[x][y]});
                }
            }
        }
        cout<<dis[n-1][n-1]<<endl;
        
    }
    return 0;
}