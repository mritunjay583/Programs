
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

// Given a sequence A of size N, find the length of the longest increasing 
// subsequence from a given sequence .
// The longest increasing subsequence means to 
// find a subsequence of a given sequence in which the subsequence's elements are in sorted order, 
// lowest to highest, and in which the subsequence is as long as possible. 
// This subsequence is not necessarily contiguous, or unique.

// Note: Duplicate numbers are not counted as increasing subsequence.


// Input:
// 16
// 0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
// 6
// 5 8 3 7 9 1

// Output:
// 6
// 3
#include<bits/stdc++.h>

using namespace std;

int lcs(int arr[],int size)
{
    int *output=new int[size];
    output[0]=1;
    for(int i=1;i<size;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>=arr[i])
            {
                continue;
            }
            int ans=output[j]+1;
            if(ans>output[i])
            {
                output[i]=ans;
            }
        }
    }
    int res=1;
    for(int i=0;i<size;i++)
    {
        if(res<output[i])
        {
            res=output[i];
        }
    }
    delete []output;
    return res;
}
int main()
{
    int arr[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<lcs(arr,size);

}






























