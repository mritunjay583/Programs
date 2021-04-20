#include<bits/stdc++.h>

using namespace std;

int getCount(string s,int low,int high,set<pair<int,int> > &se){
    int cnt=0;
    while(low>=0 && high<s.size() && s[low]==s[high]){
        if(se.count(make_pair(low,high))<=0){
            cnt++;
            se.insert(make_pair(low,high));
        }
        low--;
        high++;
    }
    return cnt;
}

int count_all_palindromes(string s){
    int n=s.size();
    set<pair<int,int> > se;
    int cnt=0;
    int low,high;

    for(int i=1;i<n;i++){
        //counting odd palindromes
        low=i-1;
        high=i;
        cnt+=getCount(s,low,high,se);

        //counting even palindromes
        low=i-1;
        high=i+1;
        cnt+=getCount(s,low,high,se);
    }
    return cnt;
}

int main(){
    string s="abbaeae";
    int res=count_all_palindromes(s);
    cout<<res<<endl;
}