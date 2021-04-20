// https://www.geeksforgeeks.org/k-smallest-elements-order-using-o1-extra-space/

// k smallest elements in same order using O(1) extra space
// You are given an array of n-elements you have to find k smallest elements from the array but they must be in the same order as they are in 
// given array and we are allowed to use only O(1) extra space.

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={5,3,9,11,0,2,6};
    int size=sizeof(a)/sizeof(a[0]);
    int k=6;

    // For each arr[i] find whether 
    // it is a part of n-smallest 
    // with insertion sort concept 
    for(int i=k;i<size;i++)
    {

        // find largest from first k-elements 
        int max_var=a[k-1];
        int pos=k-1;
        for(int i=0;i<k;i++)
        {
            if(max_var<a[i])
            {
                max_var=a[i];
                pos=i;
            }
        }

        // if largest is greater than arr[i] 
        // shift all element one place left 
        if(max_var>a[i])
        {
            int j=pos;
            while(j<k-1)
            {
                a[j]=a[j+1];
                j++;
            }
            a[k-1]=a[i];
        }
    }
    for(int i=0;i<k;i++)cout<<a[i]<<" ";cout<<endl;
}
    