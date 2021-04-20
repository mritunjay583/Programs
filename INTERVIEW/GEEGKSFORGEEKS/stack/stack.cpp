#include<bits/stdc++.h>
#define MAX 5
using namespace std;

int st[MAX];
int top=-1;

void push(int x)
{
    if(top>=MAX-1)
    {
        cout<<"overflow"<<endl;
        return;
    }
    st[++top]=x;
}

int pop()
{
    if(top==-1)
    {
        cout<<"underflow"<<endl;
    }
    int x=st[top--];
    return x;
}

int main()
{
    

}