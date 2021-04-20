#include<bits/stdc++.h>

using namespace std;

vector<string> v;
vector<string> sub_sequence(string s){
    if(s.empty()){
        v.push_back("");
        return v;
    }
    sub_sequence(s.substr(1));
    int x=v.size();
    for(int i=0;i<x;i++){
        v.push_back(s[0]+v[i]);
    }
    return v;

}
int main()
{
    string s="abce";
    
    vector<string> res=sub_sequence(s);
    for(auto x:res){
        cout<<x<<endl;
    }
}