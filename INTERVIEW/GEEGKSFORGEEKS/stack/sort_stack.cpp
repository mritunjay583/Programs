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


void sort_stack(stack<int> &st)
{
    stack<int> temp;
    while(st.size()>0)
    {
        int x=st.top();
        st.pop();
        if(temp.size()==0 || temp.top()<x)
        {
            temp.push(x);
        }
        else
        {
            while(temp.size()>0 && temp.top()>x)
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(x);
        }
        
    }
    st=temp;
}

int main()
{
    stack<int> st;
    for(int i=5;i>=0;i--)
        st.push(i);
    print(st);
    sort_stack(st);
    print(st);
}