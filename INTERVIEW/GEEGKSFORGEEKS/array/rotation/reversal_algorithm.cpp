#include<bits/stdc++.h>

using namespace std;
void right_rotate(vector<int> v,int d)
{
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+d-1);
    reverse(v.begin()+d,v.end());
    for(auto x:v)cout<<x<<" ";cout<<endl;
}
void left_rotate(vector<int> v,int d)
{
    reverse(v.begin(),v.begin()+d-1);
    reverse(v.begin()+d,v.end());
    reverse(v.begin(),v.end());
    for(auto x:v)cout<<x<<" ";cout<<endl;
}
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int d=2;
    left_rotate(v,d);
    right_rotate(v,d);
}