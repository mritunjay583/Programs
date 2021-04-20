

/*

link:---

https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/biggest-forest-700592dd/

input
--------------
5
TTTWW
TWWTT
TWWTT
TWTTT
WWTTT

*/


#include<bits/stdc++.h>
using namespace std;

int cnt;
void getbighelper(char **c,int n,int i,int j,vector<vector<bool>> &vis)
{
    
    if(i<0 || i>=n || j<0 || j>=n)
    {
        return ;
    }
    if(c[i][j]=='W' || vis[i][j]==true)
    {
        return ;
    }
    // cout<<i<<" "<<j<<" "<<c[i][j]<<endl;
    vis[i][j]=true;
    cnt++;
    //int p=0,q=0,r=0,s=0;
    getbighelper(c,n,i+1,j,vis);
    getbighelper(c,n,i,j+1,vis);
    getbighelper(c,n,i-1,j,vis);
    getbighelper(c,n,i,j-1,vis);
    return ;
}

int getbig(char **c,int n)
{
    vector<vector<bool> > visited(n,vector<bool> (n,false));
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((visited[i][j]==false) && (c[i][j]!='W'))
            {
                cnt=0;
                getbighelper(c,n,i,j,visited);
                // cout<<cnt<<endl;
                if(mx<cnt)
                mx=cnt;
                // cout<<"\n-------------\n";
            }
        }
    }
    return mx;
   
}

int main()
{
    int n;
    cin>>n;
    char **c=new char*[n];
    for(int i=0;i<n;i++)
    {
        c[i]=new char[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c[i][j];
        }
    }
    // cout<<"\n ---data---- \n";
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<getbig(c,n);
    
    for(int i=0;i<n;i++)
    delete[] c[i];
    
    delete[] c;
    return 0;
}