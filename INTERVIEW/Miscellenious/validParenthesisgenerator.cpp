#include<bits/stdc++.h>
using namespace std;
void solve(int n,int left,int right,string s,vector<string> &res){
    if(left+right==2*n){
        res.push_back(s);
        return;
    }
    if(left<n){
        solve(n,left+1,right,s+"(",res);
    }
    if(right<left)
        solve(n,left,right+1,s+")",res);
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    solve(n,0,0,"",res);
    return res;
}
int main(){
    int n=5;
    vector<string> res=generateParenthesis(n);
    for(auto x:res)cout<<x<<endl;cout<<endl;
}