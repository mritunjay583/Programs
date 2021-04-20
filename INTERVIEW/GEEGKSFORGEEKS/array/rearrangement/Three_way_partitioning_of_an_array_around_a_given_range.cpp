#include<bits/stdc++.h>

using namespace std;

void partition_in_l_to_r(int a[],int size,int l,int r)
{
    int start=0;
    int end=size-1;
    int i=0;
    while(i<=end)
    {
        if(a[i]<l)
            swap(a[i++],a[start++]);
        else if(a[i]>r)
            swap(a[i],a[end--]);
        else
            i++;
    }
    for(int i=0;i<size;i++)cout<<a[i]<<" ";cout<<endl;
}

int main()
{
    int a[]={4,4,5,7,8,1,2,3,6,5,6,6,7,9,10};
    int size=sizeof(a)/sizeof(a[0]);
    int l=4;
    int r=7;
    partition_in_l_to_r(a,size,l,r);
}