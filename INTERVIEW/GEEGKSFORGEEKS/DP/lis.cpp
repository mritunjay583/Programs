#include<bits/stdc++.h>
using namespace std;



// time O(n*n)
//space O(n)
int LIS(int arr[],int size)
{
    int lisArr[size]={1};
    for(int i=1;i<size;i++)
    {

        int mx=0;
        lisArr[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
                mx=max(mx,lisArr[j]);
        }
        lisArr[i]+=mx;


    }
    int ans=*max_element(lisArr,lisArr+size);
    return ans;
}

int main()
{
    int arr[]={50, 3, 10, 7, 40, 80};
    int size=sizeof(arr)/sizeof(arr[0]);
    int res=LIS(arr,size);
    cout<<res<<endl;
}
