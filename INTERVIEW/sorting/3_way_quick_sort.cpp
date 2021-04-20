#include<bits/stdc++.h>

using namespace std;

void print(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void _3_way_quick_sort(int a[],int low,int high)
{
    if(low>=high)
    return;

    //code for partition
    int lt=low,gt=high;
    int pivot=a[low];
    int i=low;
    while(i<=gt)
    {
        if(a[i]<pivot){swap(a[lt++],a[i++]);}
        else if(a[i]==pivot){i++;}
        else if(a[i]>pivot){swap(a[i],a[gt--]);}
    }

    //recursive call
    _3_way_quick_sort(a,low,lt-1);
    _3_way_quick_sort(a,gt+1,high);

}

int main()
{
    int a[]={53,234,534,23,4,33,54,33,54,2,2,-1,2,-1};
    int size=sizeof(a)/sizeof(a[0]);
    print(a,size);
    _3_way_quick_sort(a,0,size-1);
    print(a,size);
}