#include<bits/stdc++.h>

using namespace std;

int partition1(int [],int size,int k);
int driver_kth_largest_element(int arr[],int k,int left,int right)
{
    int partition_element=partition1(arr,left,right);
}
int kth_largest_element(int arr[],int size,int k)
{
    driver_kth_largest_element(arr,k,0,size);
}

int main()
{
    int arr[]={4,3,6,1,7,8,3,2,0,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    int k=4;
    cout<<kth_largest_element(arr,size,k);
}