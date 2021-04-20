#include<bits/stdc++.h>

using namespace std;

struct node
{
    int a,b,c;
    node(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
    }
};
struct cmp
{
    bool operator()(node x,node y)  /// implement this function just 
    {                               /// opposite you implement for sorting lists
        if(x.c!=y.c)
        return x.c>y.c;
        else
        if(x.b!=y.b)
        return x.b>y.b;
        else
        return x.a>y.a;
    }
};

int main()
{
    priority_queue<node,vector<node>,cmp> q;
    q.push({1,1,-2});
    q.push({2,4,0});
    q.push({5,1,-2});
    q.push({8,7,-2});
    q.push({7,8,1});
    q.push({1,2,10});
    while(q.empty()==false)
    {
        cout<<q.top().a<<" "<<q.top().b<<" "<<q.top().c<<endl;
        q.pop();
    }
}