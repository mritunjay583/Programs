#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    int arr_num;
    int index;
    node(int a,int b,int c)
    {
        val=a;
        arr_num=b;
        index=c;
    }
};
struct cmp
{
    bool operator()(node x,node y)
    {
        return x.val>y.val;
    }
};

int main()
{
    int k=3;
    int n=5;
    int arr[3][5]={{4, 7, 9, 12, 15},
                    {0, 8, 10, 14, 20},
                    {6, 12, 16, 30, 50}};

    priority_queue<node,vector<node>,cmp> pq;
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],i,0});
    }

    while(true)
    {
        node temp=pq.top(); 
        cout<<temp.val<<endl;
        pq.pop();
        if(temp.index==n-1)
            break;
        pq.push({arr[temp.arr_num][temp.index+1],temp.arr_num,temp.index+1});
    }

    while(pq.size()>0)
    {
        cout<<pq.top().val<<" ";
        pq.pop();
    }
    

}