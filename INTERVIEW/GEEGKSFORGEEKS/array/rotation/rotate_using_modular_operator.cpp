
// this is called quick left rotation 
// time O(1)
// space O(2*n)
// used when multiple queries of left rotation comes
#include<bits/stdc++.h>

using namespace std;

void find_all_rotations(int a[],int n)
{
    int d=0;
    while(d<n)
    {
        // a[(i+d)%n]  for left rotation
        //a[(i-d+n)%n] for right rotation
        for(int i=0;i<n;i++)
        {
            cout<<a[(i-d+n)%n]<<" ";
        }
        d++;
        cout<<endl;
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    find_all_rotations(a,n);
}