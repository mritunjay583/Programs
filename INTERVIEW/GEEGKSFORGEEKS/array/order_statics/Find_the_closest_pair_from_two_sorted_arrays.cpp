// https://www.geeksforgeeks.org/given-two-sorted-arrays-number-x-find-pair-whose-sum-closest-x/

// Find the closest pair from two sorted arrays

// We are given two arrays ar1[0…m-1] and ar2[0..n-1] and a number x, 
// we need to find the pair 
// ar1[i] + ar2[j] such that absolute value of 
// (ar1[i] + ar2[j] – x) is minimum.
#include<bits/stdc++.h>

using namespace std;

void find_closet_pair(int ar1[],int m,int ar2[],int n,int x)
{
        // Initialize the diff between pair sum and x. 
    int diff = INT_MAX; 
  
    // res_l and res_r are result indexes from ar1[] and ar2[] 
    // respectively 
    int res_l, res_r; 
  
    // Start from left side of ar1[] and right side of ar2[] 
    int l = 0, r = n-1; 
    while (l<m && r>=0) 
    { 
       // If this pair is closer to x than the previously 
       // found closest, then update res_l, res_r and diff 
       if (abs(ar1[l] + ar2[r] - x) < diff) 
       { 
           res_l = l; 
           res_r = r; 
           diff = abs(ar1[l] + ar2[r] - x); 
       } 
  
       // If sum of this pair is more than x, move to smaller 
       // side 
       if (ar1[l] + ar2[r] > x) 
           r--; 
       else  // move to the greater side 
           l++; 
    } 
  
    // Print the result 
    cout << "The closest pair is [" << ar1[res_l] << ", "
         << ar2[res_r] << "] \n";

}

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int x = 32; 
    int n1=sizeof(ar1)/sizeof(ar1[0]);
    int n2=sizeof(ar2)/sizeof(ar2[0]);
    find_closet_pair(ar1,n1,ar2,n2,x);


}