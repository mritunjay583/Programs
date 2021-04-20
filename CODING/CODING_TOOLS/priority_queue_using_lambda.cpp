#include<bits/stdc++.h>

using namespace std;

struct node
{
    int x;int y;
    node(int a,int b){
        x=a;
        y=b;
    }
};

int main()
{
    auto cmp=[](node x,node y)->bool
    {
        return x.x>y.x;
    };
    priority_queue<node,vector<node>,decltype(cmp)> pq(cmp);
    
    pq.push({1,2});
    pq.push({3,2});
    cout<<pq.top().x<<" "<<pq.top().y<<endl;

}