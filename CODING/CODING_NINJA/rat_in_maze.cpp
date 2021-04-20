#include<bits/stdc++.h> 
using namespace std;

const int m=4;

void print(int maze[m][m])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve(int maze[m][m],int temp[m][m],int row,int col)
{
    if(row == m-1 && col == m-1)
    {
        temp[row][col]=1;
        print(temp);
        return;
    }
    
    if(row <0 || row>=m || col<0 || col>=m)
    {
        return;
    }
    
    if(maze[row][col]==0 || temp[row][col]==1)
    {
        return;
    }

    temp[row][col]=1;
    solve(maze,temp,row+1,col);
    solve(maze,temp,row,col+1);
    solve(maze,temp,row-1,col);
    solve(maze,temp,row,col-1);
    temp[row][col]=0;

}


int main()
{
    int maze[m][m]={{1,1,1,0},
                    {0,1,1,1},
                    {1,1,1,1},
                    {1,0,1,1}};
    int temp[m][m]={0};
    solve(maze,temp,0,0);
//   print(maze);  
}