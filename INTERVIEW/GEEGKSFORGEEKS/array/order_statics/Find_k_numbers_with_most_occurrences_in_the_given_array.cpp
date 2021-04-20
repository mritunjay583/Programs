#include<bits/stdc++.h>

using namespace std;


void K_numbers_with_most_occurance_1(int a[],int size,int k)
{
    unordered_map<int,int> ma;
    for(int i=0;i<size;i++)
        ma[a[i]]++;

    //  you can use proority queue instead of sorting 
    // it will decrease compexity
    sort(a,a+size,[&](int a,int b)->bool
    {
        if(ma[a]!=ma[b])
            return ma[a]>ma[b];
        else 
            return a>b;
    });
    unordered_set<int> se;
    int i=0;
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(se.count(a[i])==0)
        {
            se.insert(a[i]);
            cout<<a[i]<<" ";
            cnt++;
            if(cnt==k)
                break;
        }
    }
}
int main()
{
    int a[]={7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int size=sizeof(a)/sizeof(a[0]);
    int k=4;
    K_numbers_with_most_occurance_1(a,size,k);
    // K_numbers_with_most_occurance_2(a,size,k);
}