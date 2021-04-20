#include<bits/stdc++.h>


using namespace std;

void buildTree(int *a,int *tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=a[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}

void updateTree(int a[],int *tree,int start,int end,int treeNode,int idx,int val)
{
    if(start==end)
    {
        a[idx]=val;
        tree[treeNode]=val;
        return;
    }
    int mid=(start+end)/2;
    if(idx > mid)
    {
        updateTree(a,tree,mid+1,end,2*treeNode+1,idx,val);
    }
    else
    {
        updateTree(a,tree,start,mid,2*treeNode,idx,val);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    
}

int query(int *tree,int start,int end,int treeNode,int left,int right)
{
    //Completly outside given range
    if(start>right || end < left)
    {
        return 0;
    }

    // completly inside given range
    if(start>=left && end<=right)
    {
        return tree[treeNode];
    }

    // partly inside and outside
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treeNode,left,right);
    int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    return ans1+ans2;

}

int main()
{
    int a[]={10,20,30,40};
    int size=sizeof(a)/sizeof(a[0]);
    int * tree=new int[4*size];
    buildTree(a,tree,0,size-1,1);
    for(int i=1;i<4*size;i++)
    {
        cout<<tree[i]<<endl;
    }
    
    
    int res=query(tree,0,size-1,1,0,2);   // 0 based indexing   
    // third argument is not segment tree always size of array 
    //forth argument is always equal to 1
    //fith and sixth are L and R of given range
                                        
    cout<<res;
}