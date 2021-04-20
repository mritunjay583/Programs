#include<bits/stdc++.h>

using namespace std;

//you can use the same technique to sort stack

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

void bottom_insert(int x,stack<int> &st)
{   
    if(st.size()==0)
    {
        st.push(x);
        return;
    }
    int t=st.top();
    st.pop();
    bottom_insert(x,st);
    st.push(t);

}

void reverse(stack<int> &st)
{
    if(st.size()>0)
    {
        int t=st.top();
        st.pop();
        reverse(st);
        bottom_insert(t,st);
    }
}

int main()
{
    stack<int> st;
    for(int i=0;i<5;i++)
        st.push(i);
    print(st);
    reverse(st);
    print(st);
}