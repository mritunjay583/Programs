#include<bits/stdc++.h>

using namespace std;

int find(int arr[],int size,int k)
{
    int low=0;
    int high=size-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(mid-1>=0)
        {
            if(arr[mid-1]+k!=arr[mid])
            {
                return arr[mid-1]+k;
            }
        }
        if(mid+1<size)
        {
            if(arr[mid+1]-k!=arr[mid])
            {
               return arr[mid]+k;
            }
        }

        if(2*mid==(arr[mid]-arr[0]) /* main logic */ )
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
}

int main()
{
    int arr[]={1,4,7,13,16};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=(arr[size-1]-arr[0])/size;  // because only one term is 
                    // missing in this AP
    int ele=find(arr,size,k);
    cout<<ele<<endl;                       


}