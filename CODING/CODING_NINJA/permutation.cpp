#include<bits/stdc++.h>

using namespace std;

void permute(string s,int start)
{
    if(start==s.size())
    {
        cout<<s<<endl;
        return;
    }

    for(int i=start;i<s.size();i++)
    {
        swap(s[start],s[i]);
        permute(s,start+1);
        swap(s[start],s[i]);
    }
}
int main()
{
    string s="abc";
    permute(s,0);
}