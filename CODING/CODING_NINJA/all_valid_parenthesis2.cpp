#include<bits/stdc++.h>

using namespace std;

void print_parenthesis_helper(string res,int left,int right)
{
    if(left == 0 && right == 0)
    {
        cout<<res<<endl;
        return;
    }
    if(left >0)
    {
        print_parenthesis_helper(res+"(",left-1,right);
    }
    if(left < right)
    {
        print_parenthesis_helper(res+")",left,right-1);
    }

}

void print_parenthesis(int n){
    print_parenthesis_helper("",n,n);
}


int main()
{
    int n=5;
    print_parenthesis(n);
}