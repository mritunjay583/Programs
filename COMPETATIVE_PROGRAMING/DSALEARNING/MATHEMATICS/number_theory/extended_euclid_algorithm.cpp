// aX + bY = c    ------ eq(1)
// here c = gcd(a,b)
//then find X and Y to satisfy equation  eq(1)
// X and Y will be smallest ineger

// x0 = Y;
// y0 = X-floor(a/b)*Y  

#include<bits/stdc++.h>

using namespace std;
struct Triplet
{
    int x;
    int y;
    int gcd;
};

Triplet extended_gcd(int a,int b)
{
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    Triplet ans=extended_gcd(b,a%b);
    Triplet temp;
    temp.gcd=ans.gcd;
    temp.x=ans.y;
    temp.y=ans.x-(a/b)*ans.y;
    return temp;
}

int main()
{
    Triplet res;
    res=extended_gcd(10,6);
    cout<<res.gcd<<" "<<res.x<<" "<<res.y<<endl;   
}