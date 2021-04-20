#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val,k,index;
    node(int a,int b,int c)
    {
        val=a;
        k=b;
        index=c;
    }
};
struct cmp
{
    bool operator()(struct node x,struct node y)
    {
        return x.val>y.val;
    }
};

int *merge(int arr[3][3],int k)
{
    int *res=new int[k*k]();

    priority_queue<node,vector<node>,cmp> pq;
    
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],i,0});
    }
    int j=0;
    while(pq.size()>0)
    {
        struct node temp=pq.top();
        pq.pop();
        res[j++]=temp.val;
        if(temp.index==k-1)
            continue;
        pq.push({arr[temp.k][temp.index+1],temp.k,temp.index+1});
    }
    return res;
}
int main()
{
    const int k=3;
    int arr[k][k]={{1,2,4},
                    {4,5,6},
                    {7,8,9}};
    int *res=merge(arr,k);
    for(int i=0;i<k*k;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}