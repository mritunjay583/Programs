#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<int,char> p,pair<int,char> q)
    {
        if(p.first!=q.first)
        return p.first>q.first;
        else
        return p.second<q.second;
    }
int main()
{
    vector<pair<int,char>> v{{3,'d'},{4,'a'},{4,'s'},{3,'h'}};
    for(auto x: v)cout<<x.first<<" "<<x.second<<endl;
    sort(v.begin(),v.end(),cmp);
    cout<<endl;
    for(auto x: v)cout<<x.first<<" "<<x.second<<endl;   

}