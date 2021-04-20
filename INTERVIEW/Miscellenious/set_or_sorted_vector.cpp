#include<bits/stdc++.h>

using namespace std;

int analyazeVector(){
    cout<<"analyzing vector"<<endl;
    vector<int> v{2,5,3,1,4,9};
    v.push_back(INT_MIN);
    sort(v.begin(),v.end(),greater<int>());
    for(auto x:v)cout<<x<<" ";cout<<endl;
    cout<<"lower bound : "<<*lower_bound(v.begin(),v.end(),4)<<endl;
    cout<<"upper_bound : "<<*upper_bound(v.begin(),v.end(),4)<<endl;

}

int analyzeSet(){
    cout<<"analyzingSet"<<endl;
    vector<int> v{2,5,3,1,4,9};
    set<int,greater<int> > se(v.begin(),v.end());
    // for(auto x:v)se.insert(x);
    se.insert(INT_MIN);
    for(auto x:se)cout<<x<<" ";cout<<endl;
    cout<<"lower bound : "<<*se.lower_bound(6)<<endl;
    cout<<"upper bound : "<<*se.upper_bound(6)<<endl;
}

int main(){
    analyazeVector();
    analyzeSet();
}