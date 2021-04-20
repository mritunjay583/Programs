// https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1   
// https://www.youtube.com/watch?v=m2lZRmMjebw
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

int countDistinctSubstring(string s)
{
    vector<string> v;
    for(int i=0;i<s.size();i++){
        v.push_back(s.substr(i,s.size()-i));
    }
    sort(v.begin(),v.end());
    int sum=0;
    for(int i=0;i<v.size()-1;i++){
        int j=0;
        while(j<v[i].size() && j<v[i].size() && v[i+1][j]==v[i][j]){
            j++;
        }
        sum+=j;
    }
    int temp=(s.size()*(s.size()+1))/2;
    return temp-sum+1;
}

int main()
{
    string s="ababa";
    cout<<countDistinctSubstring(s)<<endl;
}