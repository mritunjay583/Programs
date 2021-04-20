// https://www.geeksforgeeks.org/partition-problem-dp-18/
// determine whether a given set can be partitioned into 
// two subsets such that the sum of elements in both subsets is same


#include <bits/stdc++.h>
using namespace std;



//brute force 
//time O(2^n)

bool is_possible(int a[],int itr,int sum1,int sum2)
{
    if(itr==0)
        return sum1==sum2;
    if(sum1==sum2)
        return true;
    if(sum2>sum1)
        return false;
    
    return is_possible(a,itr-1,sum1-a[itr],sum2+a[itr]) ||
            is_possible(a,itr-1,sum1,sum2);
}

int main() {	
    int a[]={1,5,11,5};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=accumulate(a,a+n,0);
    if(is_possible(a,n-1,sum,0))
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
	return 0;
}