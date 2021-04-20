#include<bits/stdc++.h>


using namespace std;

int no_of_bts(int n)
{
    int arr[n+1]={0};
    arr[0]=1;  //base cases
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]*arr[i-1]+2*arr[i-2]*arr[i-1];
    }
    return arr[n];
}


int main()
{
    int h=3;
    cout<<no_of_bts(h)<<endl;
}