// https://practice.geeksforgeeks.org/problems/rotten-oranges/0
#include<bits/stdc++.h>
using namespace std;

struct org{
    int i;
    int j;
    int day;
    org(int _i,int _j,int _day){
        i=_i;
        j=_j;
        day=_day;
    }
};

int main()
 {
     //input test cases
    int t;
    cin>>t;

    while(t--){
        //r=row c=column
        int r,c;
        cin>>r>>c;

        int **mat=new int*[r];

        queue<org> q; // queue to store all rotten oranges initially
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        int fresh=0; // holds the count of fresh oranges
        
        //taking input {some preprocessing}
        for(int i=0;i<r;i++){
            mat[i]=new int[c];
            for(int j=0;j<c;j++){
                cin>>mat[i][j];
                if(mat[i][j]==2){
                    visited[i][j]=true;  //doing this for BFS traversal
                    q.push(org(i,j,0));
                }
                if(mat[i][j]==1){
                    fresh++; 
                }
            }
        }

        int res=INT_MIN; //holds the day count 
        int x[4][2]={{-1,0},{1,0},{0,-1},{0,1}};  // temprory array to do traversal

        while(q.empty()==false){
            org t=q.front();q.pop();

            res=max(res,t.day); // getting max day

            //simple bfs thing
            for(int i=0;i<4;i++){
                if(t.i+x[i][0]>=0 && t.i+x[i][0]<r 
                    && t.j+x[i][1]>=0 && t.j+x[i][1]<c){
                        if(visited[t.i+x[i][0]][t.j+x[i][1]]==false){
                        if(mat[t.i+x[i][0]][t.j+x[i][1]]==1){
                            fresh--;
                            visited[t.i+x[i][0]][t.j+x[i][1]]=true;
                            q.push(org(t.i+x[i][0],t.j+x[i][1],t.day+1));
                        }
                    }
                }
            }
        }
        //if there is still fresh orange/oranges then result will be -1
        if(fresh>0){
            cout<<"-1"<<endl;
        }
        else
        {
            cout<<res<<endl;
        }
        
    }
	return 0;
}


//sample input
// 2
// 3 5
// 2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
// 3 5
// 2 1 0 2 1 0 0 1 2 1 1 0 0 2 1