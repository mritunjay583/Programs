//https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

#include<bits/stdc++.h>
using namespace std;

int main()
{
        long long int a[]={34,8,10,3,2,80,30,33,1};
        long long int n=sizeof(a)/sizeof(a[0]);
	   
	     long long int *Lmin=new long long int[n]();
	     long long int *Rmax=new long long int[n]();
	     long long int min_val=a[0];
	     for(int i=0;i<n;i++)
	     {
	         if(a[i]<min_val)
	         {
	             min_val=a[i];
	         }
	         Lmin[i]=min_val;
	     }
	     long long int max_val=a[n-1];
	     for(int i=n-1;i>=0;i--)
	     {
	         if(max_val<a[i])
	        {
	            max_val=a[i];
	        }
	        Rmax[i]=max_val;
	     }
	     int i=0;
	     int j=0;
	     int max_far=INT_MIN;
	     while(i<n && j<n)
	     {
	         
	        if(Lmin[i]>Rmax[j])
	        {
	            i++;
	        }
	        else
	        {
	            max_far=max(max_far,j-i);
	            j++;
	        }
	       
	     }
	     cout<<max_far<<endl;
}