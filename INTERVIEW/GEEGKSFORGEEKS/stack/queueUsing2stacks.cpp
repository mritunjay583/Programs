#include<bits/stdc++.h>
using namespace std;



class Q2{
    stack<int> s;
    public:
    void push(int x){
        s.push(x);
    }
    int pop(){
        if(s.size()==1){
            int x=s.top();
            s.pop();
            return x;
        }
        if(s.size()==0){
            return -1;
        }
        int t=s.top();
        s.pop();
        int res=pop();
        s.push(t);
        return res;
    }
};

//here enqueue operation is costly
//qeueue using 2 stacks
class Q1{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.size()==0 && s2.size()==0){
            return -1;
        }
        if(s2.size()==0){
            while(s1.size()>0){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res=s2.top();
        s2.pop();
        return res;
    }
};

int main(){
    Q1 q;
    cout<<q.pop()<<endl;
    q.push(12);
    q.push(14);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    cout<<"----------\n\n";
    Q2 r;
    cout<<r.pop()<<endl;
    r.push(12);
    r.push(14);
    cout<<r.pop()<<endl;
    cout<<r.pop()<<endl;
    cout<<r.pop()<<endl;
}