#include<bits/stdc++.h>

using namespace std;

string infix_to_postfix(string infix)
{
    cout<<infix<<endl;
    stack<char> op;
    stack<string> var;
    unordered_map<char,int> value;
    value['-']=0;
    value['+']=0;
    value['*']=1;
    value['/']=1;
    value['^']=2;
    int i=0;
    while(i<infix.size())
    {
        if((infix[i]>='A' && infix[i]<='Z') || 
            (infix[i]>='a' && infix[i]<='z'))
        {
            string t(1,infix[i]);
            // cout<<t<<endl;
            var.push(t);
            cout<<var.top()<<endl;
        }
        else
        {
            if(infix[i]=='(' || op.top()=='(')
            {
                op.push(infix[i]);
                // cout<<op.top()<<endl;
            }
            else if(value[infix[i]]>value[op.top()])
            {
                op.push(infix[i]);
            }
            else
            {
                if(infix[i]==')')
                {
                    while(true)
                    {
                        char temp=op.top();op.pop();
                        if(temp=='(')
                            break;
                        string s1=var.top();var.pop();
                        string s2=var.top();var.pop();
                        string res=s2+s1+temp;
                        var.push(res);
                    }
                }
                else
                {
                    while(true)
                    {
                        if(op.top()=='(' || value[op.top()]<value[infix[i]])
                        {
                            break;
                        }
                        else
                        {
                            char temp=op.top();op.pop();
                            string s1=var.top();var.pop();
                            string s2=var.top();var.pop();
                            string res=s2+s1+temp;
                            var.push(res);
                        }
                        
                    }
                    op.push(infix[i]);
                }
                
            }
        }
        i++;
    }
    // cout<<var.top().size()<<endl;
    // cout<<var.top();
    return var.top();
    // return "sahil";
}

int main()
{
    string infix="a+b*(c^d-e)^(f+g*h)-i";
    infix="("+infix+")";
    string postfix=infix_to_postfix(infix);
    cout<<postfix<<endl;
}