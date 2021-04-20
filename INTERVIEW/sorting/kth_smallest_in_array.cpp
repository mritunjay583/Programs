// https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

#include<bits/stdc++.h>
using namespace std;
int pivot(int a[],int st,int en){
    int i=st-1;
    int j=st;
    int p=rand()%(en-st+1)+st;  //randomness is very important 
    swap(a[en],a[p]);
    p=en;
    while(j<=en){
        if(a[j]<a[p]){
            i++;
            swap(a[j],a[i]);
        }
        j++;
    }
    swap(a[i+1],a[p]);
    return i+1;
}
int kth(int a[],int st,int en,int k){
    if(st==en){
        if(st==k)
        return a[st];
        else
        return INT_MAX;
    }
    int pi=pivot(a,st,en);
    if(pi==k)
        return a[pi];
    else if(pi>k)
            return kth(a,st,pi-1,k);
    else return kth(a,pi+1,en,k);
}
int main()
 {
	int t;
	scanf("%d",&t);
	while(t--){
	    int n;
	    scanf("%d",&n);
	    int a[n];
	    for(int i=0;i<n;i++)scanf("%d",&a[i]);
	    int k;
	    scanf("%d",&k);

	    int x=kth(a,0,n-1,k-1);
	    printf("%d\n",x);
        
	}
	return 0;
}