#include <bits/stdc++.h>
using namespace std;



//brute force 
//time O(2^n)

int min_sum_partition_1(int a[],int itr,int sum1,int sum2)
{
    if(itr==0)
        return abs((sum1-sum2)-sum2);
    
    return min(min_sum_partition_1(a,itr-1,sum1,sum2+a[itr]),
                min_sum_partition_1(a,itr-1,sum1,sum2));
    
}

int main() {	
    int a[]={36,7,46,40};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=accumulate(a,a+n,0);
    int res=min_sum_partition_1(a,n-1,sum,0);
    cout<<res<<endl;
	return 0;
}