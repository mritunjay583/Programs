#include<bits/stdc++.h>

using namespace std;

long long recursiveSolution(int nthfib)
{
    if(nthfib<=1)
    {
        return 1;
    }
    return recursiveSolution(nthfib-1)+recursiveSolution(nthfib-2);
}
////////////////////////////////////////////////////////////////////////
long long dp1Helper(int nthfib,int res[])
{
    if(nthfib<=1)
    {
        res[nthfib]=1;
        return res[nthfib];
    }
    if(res[nthfib])
    return res[nthfib];
    res[nthfib]=dp1Helper(nthfib-1,res)+dp1Helper(nthfib-2,res);
    return res[nthfib];
}
long long dp1(int nthfib)
{
    int res[nthfib+1]={0};
    return dp1Helper(nthfib,res);
}
//////////////////////////////////////////////////////////////////////
long long dp2(int nthfib)
{
    long long res[nthfib+1]={0};
    res[0]=1;
    res[1]=1;
    for(int i=2;i<=nthfib;i++)
    {
        res[i]=res[i-1]+res[i-2];
    }
    return res[nthfib];
} 
///////////////////////////////////////////////////////////////////////
long long dp3(int nthfib)
{
    int a=1;
    int b=1;
    int res=1;
    for(int i=2;i<=nthfib;i++)
    {
        res=a+b;
        b=a;
        a=res;
    }
    return res;
}
int main()
{
    int nthfib=12;
    cout<<recursiveSolution(nthfib)<<endl;
    cout<<dp1(nthfib)<<endl;
    cout<<dp2(nthfib)<<endl;
    cout<<dp3(nthfib)<<endl;
}