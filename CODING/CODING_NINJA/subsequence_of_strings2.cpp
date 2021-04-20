#include<bits/stdc++.h>

using namespace std;

void subsequence(string s,string t){
    if(s.empty()==true)
    {
        cout<<t<<endl;
        return;
    }
    subsequence(s.substr(1),t);
    subsequence(s.substr(1),s.substr(0,1)+t);
}

int main()
{
    string s="abcd";
    cout<<s.substr(1);
    subsequence(s,"");
}
