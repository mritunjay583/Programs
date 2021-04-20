#include<bits/stdc++.h>

using namespace std;

int _get_fixed_point(int arr[],int low,int high)
{
    if(low>high)
    return -1;
    int mid=(low+high)/2;
    
    // main logic

    if(arr[mid]==mid)
    return mid;
    if((arr[mid]-mid)>0)
    {
        return _get_fixed_point(arr,low,mid-1);
    }
    else
    {
        return _get_fixed_point(arr,mid+1,high);
    }

    //
    
}

int main()
{
    //elements are distinct

    int arr[]={-10, -5, 3, 4, 7, 9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int fixed_point=_get_fixed_point(arr,0,size-1);
    cout<<fixed_point<<endl;


    // think?? what will you do if elemnts are repeated
    // do it later
    
}