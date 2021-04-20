#include<bits/stdc++.h>

using namespace std;

void print(stack<int> st)
{
    stack<int> temp;
    while(st.size()>0)
    {
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0)
    {
        st.push(temp.top());
        temp.pop();
    }
}

void reverse(stack<int> &st,stack<int> &temp)
{
    if(st.size()<=0)
        return;
    temp.push(st.top());
    st.pop();
    reverse(st,temp);
}

int main()
{
    stack<int> st;
    for(int i=0;i<5;i++)
        st.push(i);
    print(st);
    stack<int> temp;
    reverse(st,temp);
    st=temp;
    print(st);
}