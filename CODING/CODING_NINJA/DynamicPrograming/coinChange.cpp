#include<bits/stdc++.h>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int rcountWays(int value,int d[],int n)
{
    if(value<0 || n<=0)
    {
        return 0;
    }
    if(value==0)
    {
        return 1;
    }
    return rcountWays(value-d[0],d,n)+rcountWays(value,d+1,n-1);

}
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////


int main()
{
    int n=3;
    int d[]={1,2,3};
    int value=4;
    cout<<rcountWays(value,d,n);
    cout<<dp1countWays(value,d,n);
}