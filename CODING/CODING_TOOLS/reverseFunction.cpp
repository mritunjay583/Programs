#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s="sahil";
    vector<char> v{'s','a','h','i','l'};
    char arr[5]={'s','a','h','i','l'};

    cout<<s<<endl;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    
    for(auto x:v)cout<<x<<" ";cout<<endl;
    reverse(v.begin(),v.end());
    for(auto x:v)cout<<x<<" ";cout<<endl;

    for(auto x:arr)cout<<x<<" ";cout<<endl;
    reverse(arr,arr+5);
    for(auto x:arr)cout<<x<<" ";cout<<endl;

}