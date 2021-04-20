// used in solving (a/b)%m=0
//(a/b)%m=a*modularInverseOf(b)
//using extended euclid algorithm to solve 
// a*X + m*Q =1  where Q is an integer 
// here we need to find X 
// and that will be modular inverse of a = b = X 
#include<bits/stdc++.h>

using namespace std;

struct Triplet{
    int gcd;
    int x;
    int y;
};
Triplet extended_euclid(int p,int q)
{
    if(q==0)
    {
        Triplet ans;
        ans.gcd=p;
        ans.x=1;
        ans.y=0; // here ans.y can have any arbitary value
        return ans;
    }
    Triplet temp=extended_euclid(q,p%q);
    Triplet ans;
    ans.gcd=temp.gcd;
    ans.x=temp.y;
    ans.y=temp.x-(p/q)*temp.y;
    return ans;
}

int modular_inverse(int a,int m)
{
    Triplet res=extended_euclid(a,m);
    return (res.x+m)%m;   /// res.x is answer but to avoid
}                       // (-ve) values use (res.x+m)%m

int main()
{
    int a=5;
    int m=11;
    cout<<modular_inverse(a,m)<<endl;

}

// better explanation 
//  (a * b)%m=1  ---- eq(1)
// here you have given a and m 
// you need to find smallest positive integer b so that 
// eq(1) will be true