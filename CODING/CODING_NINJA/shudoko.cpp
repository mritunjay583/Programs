#include<bits/stdc++.h>

using namespace std;

const int n=9;

void print(int shudoku[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<shudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool checkVertical(int shudoku[n][n],int x,int y,int val)
{
    for(int i=0;i<n;i++)
    {
        if(shudoku[i][y]==val)
        {
            return false;
        }
    }
    return true;
}
bool checkHorizontal(int shudoku[n][n],int x,int y,int val)
{
    for(int i=0;i<n;i++)
    {
        if(shudoku[x][i]==val)
        {
            return false;
        }
    }
    return true;
}
bool checkGrid(int shudoku[n][n],int x,int y,int val)
{
    int xbase=x-x%3;
    int ybase=y-y%3;
    for(int i=xbase;i<xbase+3;i++)
    {
        for(int j=ybase;j<ybase+3;j++)
        {
            if(shudoku[i][j]==val)
            {
            return false;
            }
        }
    }
    return true;
}
bool canFill(int shudoku[n][n],int x,int y,int val)
{
    bool a=checkHorizontal(shudoku,x,y,val);
    bool b=checkVertical(shudoku,x,y,val);
    bool c=checkGrid(shudoku,x,y,val);
    return a&b&c;
}

int cnt=49;
bool solve(int shudoku[n][n],vector<pair<int,int> >v,int index)
{
    if(index==v.size())
    {
        print(shudoku);
        return true;
    }
    for(int i=1;i<=9;i++)
    {
        if(canFill(shudoku,v[index].first,v[index].second,i))
        {
            shudoku[v[index].first][v[index].second]=i;
            if(solve(shudoku,v,index+1))
            return true;
            else
            shudoku[v[index].first][v[index].second]=0;
        }
    }
    return false;
}
int main()
{
    int shudoku[n][n]={{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
    
    
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(shudoku[i][j]==0)
            v.push_back(make_pair(i,j));
        }
    }
    print(shudoku);
    cout<<solve(shudoku,v,0);
}