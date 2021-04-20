#include<bits/stdc++.h>

using namespace std;

void build(int *arr,int *tree,int start,int end,int tn)
{
    if(start==end)
    {
        tree[tn]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(arr,tree,start,mid,2*tn);
    build(arr,tree,mid+1,end,2*tn+1);
    tree[tn]=min(tree[2*tn],tree[2*tn+1]);
}

void lazyupdate(int *lazy,int *tree,int start,int end,int cur,int left,int right,int incr)
{
    
    if(start>end)
    {
        return;
    }

    if(lazy[cur]!=0)
    {
        tree[cur]+=lazy[cur];
        if(start!=end)
        {
            lazy[2*cur]+=lazy[cur];
            lazy[2*cur+1]+=lazy[cur];
        }
        lazy[cur]=0;
    }
    /// no overlap
    if(start > right || end < left)
    {
        return;
    }

    //full overlap
    if(start>=left && end<=right)
    {
        
        tree[cur]+=incr;
        if(start!=end)
        {
            lazy[2*cur]+=incr;
            lazy[2*cur+1]+=incr;
        }
        return;
    }
    //partial overlap
    int mid=(start+end)/2;
    lazyupdate(lazy,tree,start,mid,2*cur,left,right,incr);
    lazyupdate(lazy,tree,mid+1,end,2*cur+1,left,right,incr);
    tree[cur]=min(tree[2*cur],tree[2*cur+1]);

}

int query(int *tree,int *lazy,int start,int end,int tn,int left,int right)
{
    if(start>right || end<left)
    {
        return INT_MAX;
    }
    if(lazy[tn]!=0)
    {
        tree[tn]+=lazy[tn];
        if(start!=end)
        {
            lazy[2*tn]+=lazy[tn];
            lazy[2*tn+1]+=lazy[tn];
        }
        lazy[tn]=0;
    }
    if(start>=left && end<=right)
    {
        return tree[tn];
    }
    int mid=(start+end)/2;
    int ans1=query(tree,lazy,start,mid,2*tn,left,right);
    int ans2=query(tree,lazy,mid+1,end,2*tn+1,left,right);
    return min(ans1,ans2);
}

int main()
{
    int arr[]={2,5,1,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *tree=new int[4*n];
    int *lazy=new int[4*n]();
    build(arr,tree,0,n-1,1);
    lazyupdate(lazy,tree,0,n-1,1,0,3,10);
    // cout<<query(tree,0,n-1,1,0,1)<<endl;
    // lazyupdate(lazy,tree,0,n-1,1,0,2,2);
    cout<<query(tree,lazy,0,n-1,1,0,1)<<endl;

}