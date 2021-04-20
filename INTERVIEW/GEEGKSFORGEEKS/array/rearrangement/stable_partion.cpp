////Rearrange positive and negative numbers 


// if you want to stable partiotining you can approch 
//using reversing array
#include<bits/stdc++.h>

using namespace std;

void rearrange(int a[],int start,int end)
{
    if(start==end)
        return;
    
    rearrange(a,start+1,end);

    if(a[start]>=0)
    {
        reverse(a+start+1,a+end);
        reverse(a+start,a+end);
    }
}

int main()
{
    int a[]={12, 11, -13, -5, 6, -7, 5, -3, -6};
    int size=sizeof(a)/sizeof(a[0]);

    // this can be done to do stable parition this array 
    // stable_partition(a,a+size,[](int x){return x<0;});

    int neg_count=count_if(a,a+size,[](int x){return x<0;});
    rearrange(a,0,size-1);
    reverse(a+neg_count-1,a+size);
    for(auto x:a)cout<<x<<" ";cout<<endl;

}