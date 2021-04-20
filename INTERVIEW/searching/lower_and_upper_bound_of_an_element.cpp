#include<bits/stdc++.h>

using namespace std;

void getLowerUpper(int arr[],int size,int target)
{
    int low=0;
    int high=size-1;
    int lowerBound=-1;
    int upperBound=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            lowerBound=upperBound=arr[mid];
            break;
        }
        if(arr[mid]<target)
        {
            low=mid+1;
            lowerBound=arr[mid];
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
            upperBound=arr[mid];
        }
    }
    cout<<"lower_bound of "<<target<<" in arr is : "<<lowerBound<<endl;
    cout<<"upper_bound of "<<target<<" in arr is : "<<upperBound<<endl;
    cout<<" ----------  "<<endl;
}

int main()
{
    int arr[]={1,4,4,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<=10;i++)
    {
        getLowerUpper(arr,size,i);
    }
}