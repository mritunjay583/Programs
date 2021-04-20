#include<bits/stdc++.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
//////time_complexity O( nlong(n) )//////////////////////////////////
/////////////////////////////////////////////////////////////////////

int minimum_swap(int arr[],int n)
{
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++)
    {
        v[i].first=arr[i];
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    vector<bool> vis(n,false);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i] || v[i].second==i)
        continue;
        
        int j=i;
        int cycle_size=0;
        while(!vis[j])
        {
            vis[j]=true;
            j=v[i].second;
            cycle_size++;
        }
        if(cycle_size>0)
        {
            ans+=(cycle_size-1);
        }
    }
    return ans;
}

///////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


int main()
{
    int arr[]={2,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int swaps=minimum_swap(arr,n);
    cout<<swaps<<endl;
}