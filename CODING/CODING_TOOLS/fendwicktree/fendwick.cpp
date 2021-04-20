#include<bits/stdc++.h>

using namespace std;

// for your ease make indexing from 1 in BIT
// increment index //  index += index & (-index)
// decrement index // index -= index & (-index)

void update(int index,int value,int *BIT,int n)
{
    for(;index<=n;index+=index&(-index))
    {
        BIT[index]+=value;
    }
}

int query(int index,int *BIT)
{
    int sum=0;
    for(;index>0;index -= index&(-index))
    {
        sum+=BIT[index];
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1]();
    int *BIT=new int[n+1]();
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(i,arr[i],BIT,n);
    }
    cout<<"sum of index 2 to index 6 : "<<query(6,BIT)-query(1,BIT)<<endl;
    cout<<"sum of index 0 to 5 : "<<query(5,BIT)<<endl;
}