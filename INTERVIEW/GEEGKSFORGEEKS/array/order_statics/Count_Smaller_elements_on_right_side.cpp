// https://www.geeksforgeeks.org/count-smaller-elements-on-right-side/
#include<bits/stdc++.h>

using namespace std;


void small_element_on_right(int a[],int size)
{
    multiset<int> se;
    int right_small[size];
    for(int i=size-1;i>=0;i--)
    {
        se.insert(a[i]);
        int t=distance(se.begin(),se.lower_bound(a[i]));
        right_small[i]=t;
    }
    for(auto x:right_small)cout<<x<<" ";cout<<endl;
}
int main()
{
    int a[]={7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int size=sizeof(a)/sizeof(a[0]);
    small_element_on_right(a,size);
}