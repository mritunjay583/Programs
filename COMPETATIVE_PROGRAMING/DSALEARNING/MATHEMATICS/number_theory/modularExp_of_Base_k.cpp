// calculating (a^b)%m 
// where b is of any base and can be very large
// so that it can not be fit long long 

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long a=37696;
    string b="2121101110112";  // b is of base 3
    long long m=91835;
    long long res=1;
    for(int i=b.size()-1;i>=0;i--)
        {
            if(b[i]=='1')
            {
                res=(res*a)%m;
            }
            if(b[i]=='2')
            {
                res=(((res*a)%m)*a)%m;
            }
            a=(((a*a)%m)*a)%m;

            // furthur for b[i]=='3' for base 4
        }
        cout<<res<<endl;
} 