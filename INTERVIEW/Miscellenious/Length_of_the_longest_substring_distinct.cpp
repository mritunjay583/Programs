// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
#include <bits/stdc++.h>
using namespace std;


int lengthOfLongestSubstringOfDistinctCharacter(string s){
    if(s.size()<=1)
    return s.size();
    int i=0;
    int j=0;
    int max_len=0;
    unordered_map<int,int> ma;
    while(j<s.size()){
        if(ma.count(s[j])>0 && ma[s[j]]>=i){
            max_len=max(max_len,j-i);
            i=ma[s[j]]+1;
            ma[s[j]]=j;
        }
        else{
            ma[s[j]]=j;
        }
        j++;
    }
    max_len=max(max_len,j-i);
    return max_len;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int res=lengthOfLongestSubstringOfDistinctCharacter(s);
        cout<<res<<endl;
    }
}


