// we will see how can we use priority_queue 
// for custom datatypes like class or structure.
//storing pairs in priority queue

#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int,char> p,pair<int,char> q)
    {
        if(p.first!=q.first)
        return p.first>q.first;
        else
        return p.second<q.second;
    }
};


int main()
{
    string s;
    cout<<"enter string "<<endl;
    cin>>s;
    map<char,int> hashmap;
    for(int i=0;i<s.size();i++)
    {
        hashmap[s[i]]++;
    }
    
    priority_queue<pair<int,char> ,vector<pair<int,char>> ,cmp> pq;

    for(auto x:hashmap)
    {
     pq.push(make_pair(x.second,x.first));
     if(pq.size()>4)
     pq.pop();
    }

    while(pq.size()>0)
    {
        cout<<pq.top().second<<" "<<pq.top().first<<endl;
        pq.pop();
    }
}