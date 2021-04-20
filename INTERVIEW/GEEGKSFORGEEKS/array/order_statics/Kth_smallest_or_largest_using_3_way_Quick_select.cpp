#include<bits/stdc++.h>

using namespace std;


pair<int,int> _3_way_partition(int a[],int low,int high)
{
    // it is very important to choose random pivot
    srand(time(0));
    int random=rand()%(high-low+1)+low;
    swap(a[random],a[high]);
    
    int start=low;
    int end=high;
    int i=low;
    int piv=a[high];
    while(i<=end)
    {
        if(a[i]<piv)
            swap(a[i++],a[start++]);
        else if(a[i]>piv)
            swap(a[i],a[end--]);
        else
            i++;
    }
    pair<int,int> res;
    res.first=start;
    res.second=end;
    return res;
}

int K_th_smallest_4_util(int a[],int start,int end,int k)
{
    if(start>end)
        return -1;
    pair<int,int> id=_3_way_partition(a,start,end);
    if(k>=id.first && k<=id.second)
        return a[id.first];
    else if(k<id.first)
        return K_th_smallest_4_util(a,start,id.first-1,k);
    else if(k>id.second)
        return K_th_smallest_4_util(a,id.second+1,end,k);
}

int K_th_smallest_4(int a[],int size,int k)
{   
    if(k>size)
        return -1;
    return K_th_smallest_4_util(a,0,size-1,k);
    
}
int main()
{
    int a[]={5,7,2,3,9,2,8,3,2,3,4,2,3,8};
    int size=sizeof(a)/sizeof(a[0]);
    int k=5;
    int res=K_th_smallest_4(a,size,k-1);   //O(n) 
    if(res==-1)
        cout<<k<<" is bigger than "<<size<<endl;
    else
        cout<<k<<"th smallest element is : "<<res<<endl;
    
}