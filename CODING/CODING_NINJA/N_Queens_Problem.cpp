#include<bits/stdc++.h>

using namespace std;
// Q[i][j]=-1 ---   place for queen
// Q[i][j]=0  ---   can place the queen
// Q[i][j]>0  ---   cannot place the queen

const int n=4;    /// size of matrix(chess board)

void print(int Q[n][n]) // function to print chess board
{     
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<"|"<<" ";
        for(int j=0;j<n;j++){
            if(Q[i][j]==-1)
            cout<<Q[i][j]<<"  ";
            else
            cout<<"0""  ";
        }
        cout<<"|";
        cout<<endl;  
    }
    cout<<"\n";
}
void reserve(int Q[n][n],int row,int col,int val)    //placing a queen at Q[row][col]
{                                                    // val==1 place queen  
                                                     //val==-1 not place queen

    for(int i=0;i<n;i++)
    Q[row][i]+=val;

    for(int i=0;i<n;i++)
    Q[i][col]+=val;

    int i=row;
    int j=col;

    while(i>=0 && j>=0) 
    Q[i--][j--]+val;
    
    i=row;
    j=col;
    
    while(i<n && j<n)
    Q[i++][j++]+=val;
    
    i=row;
    j=col;
    
    while(i<n && j>=0)
    Q[i++][j--]+=val;
    
    i=row;
    j=col;
    
    while(i>=0 && j<n)
    Q[i--][j++]+=val; 

    if(val==-1)
    {
        Q[row][col]=0;
    }
    else{
    Q[row][col]=-1;
    }
    
}
vector<pair<int,int>> v;  // store the indices of queen
int no_of_ways=0;
void  solve(int Q[n][n],int row,int col)
{
    if(row>=n) // base case
    {
        no_of_ways++;
        print(Q);
        cout<<"place for queens :-"<<endl;
        for(auto x:v){
            cout<<"("<<x.first<<","<<x.second<<")"<<" ";
            
        }
        cout<<endl;
        return;
    }
    for(int i=col;i<n;i++){
        if(Q[row][i]==0)
        {
            reserve(Q,row,i,1);  // placing queen at Q[row][i]
            v.push_back(make_pair(row,i)); 
            solve(Q,row+1,0);   // recursive call
            //backtrack (reversing our work after unsuccessful operation out recursive call)
            reserve(Q,row,i,-1); 
            v.pop_back();
        }
    }
    return ;
}
int main()
{
    
    int Q[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            Q[i][j]=0;
        }
    }
    // print(Q);
    solve(Q,0,0);
    // print(Q);
    cout<<"number of ways to place queen in  "<<n<<" X "<<n<<"  : "<<no_of_ways<<endl;
}