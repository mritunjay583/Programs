// https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings/0/
#include<bits/stdc++.h>
using namespace std;

int getCount(string s,int low,int high,unordered_set<string> &se){
    int cnt=0;
    while(low>=0 && high<s.size() && s[low]==s[high]){
        if(se.count(s.substr(low,high-low+1))<=0){
            cnt++;
            se.insert(s.substr(low,high-low+1));    
        }
        low--;
        high++;
    }
    return cnt;
}

int count_all_distinct_palindromes(string s){
    int n=s.size();
    unordered_set<string> se; // to insure not to count for duplicate strings
    int cnt=0;
    int low,high;

    //counting for distinct palindrome of length 1
    for(int i=0;i<n;i++){
        if(se.count(s.substr(i,1))<=0){
            cnt++;
            se.insert(s.substr(i,1));
        }
    }

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
    string s="abaaa";
    int res=count_all_distinct_palindromes(s);
    cout<<res<<endl;
}