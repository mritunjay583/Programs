// https://practice.geeksforgeeks.org/problems/equal-0-1-and-2/0
//count the number of substring which have equal number of 0s, 1s and 2s.

#include<bits/stdc++.h>
using namespace std;

int solve(string s)
{
    map<pair<int,int>,int > ma;
    ma[make_pair(0,0)]=1;
    int res=0;
    int cnt_0=0,cnt_1=0,cnt_2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')cnt_0++;
        else if(s[i]=='1')cnt_1++;
        else cnt_2++;

        pair<int,int> temp=make_pair(cnt_0-cnt_1,cnt_0-cnt_2);

        res+=ma[temp];
        
        ma[temp]++;

    }
    return res;
}

int main()
{
    string s="102100211";
    int res=solve(s);
    cout<<res<<endl;
}