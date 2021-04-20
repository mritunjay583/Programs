// brute force to calculate all valid parenthesis

#include<bits/stdc++.h>

using namespace std;
bool check(string brackets)
{
    stack<char> st;
    st.push('#');
    for(int i=0;i<brackets.size();i++)
    {
        if(st.top()=='(' && brackets[i]==')')  
        {
            st.pop();
        } 
        else
        {
            st.push(brackets[i]);
        }
    }
    if(st.top()=='#'){
        return true;
    }
    else
    {
        return false;
    }

}

set<string> res;
void all_valid_parenthesis(string brackets,int start)
{
    if(start==brackets.size())
    {
        if(check(brackets))
        {
        if(res.find(brackets)==res.end())
        {
            res.insert(brackets);
        }
        }
        return;
    }
    for(int i=start;i<brackets.size();i++)
    {
        swap(brackets[start],brackets[i]);
        all_valid_parenthesis(brackets,start+1);
        swap(brackets[start],brackets[i]);
    }
}

int main()
{
    int n=4;
    string brackets;
    for(int i=0;i<2*n;i++){
        if(i&1){
            brackets+="(";
        }
        else
        {
            brackets+=")";
        }
    }
    // cout<<brackets<<endl;
    all_valid_parenthesis(brackets,0);
    for(auto x:res)
    {
        cout<<x<<endl;
    }
}