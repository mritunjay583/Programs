// this method is applied when b is very very large that it will
//not fit in long long

#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int a=546;
    string b="77777777777777788888888899999";
    if(a==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        int num=0;
        for(int i=0;i<b.size();i++)
        {
            int cur=b[i]-'0';
            num=(((num%a)*10)%a + cur)%a;
        }
        int res=gcd(a,num);
        cout<<res<<endl;
    }
}