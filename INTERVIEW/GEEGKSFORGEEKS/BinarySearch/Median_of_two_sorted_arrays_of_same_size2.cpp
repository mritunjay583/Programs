// https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include <bits/stdc++.h> 
using namespace std; 

//time complexity of this algorithm is O(log(n))
int getMedian(int ar1[],int i1,int j1,int ar2[],int i2,int j2){
    int n1=j1-i1+1;
    int n2=j2-i2+1;
    if(n1==2 && n2==2){
        return (max(ar1[i1],ar2[i1])+min(ar1[j2],ar2[j2]))/2;
    }
    int m1=-1;
    int m2=-1;
    if(n1%2==0){
        m1=(ar1[n1/2+i1]+ar1[n1/2+i1-1])/2;
        m2=(ar2[n1/2+i2]+ar2[n1/2+i2-1])/2;
    }else{
        m1=ar1[n1/2+i1];
        m2=ar2[n1/2+i2];
    }
    for(int i=i1;i<=j1;i++)cout<<ar1[i]<<" ";cout<<endl;
    for(int i=i2;i<=j2;i++)cout<<ar2[i]<<" ";cout<<endl;
    cout<<"median : "<<m1<<" "<<m2<<endl;
    if(m1==m2){
        return m1;
    }else if(m1>m2){
        if(n1%2==0)
            return getMedian(ar1,i1,n1/2+i1-1,ar2,i2+n2/2,j2);
        else
            return getMedian(ar1,i1,n1/2+i1,ar2,n2/2+i2,j2);
    }else{
        if(n1%2==0){
            return getMedian(ar1,n1/2+i1,j1,ar2,i2,i2+n2/2-1);
        }else{
            return getMedian(ar1,n1/2+i1,j1,ar2,i2,i2+n2/2);
        }
    }
}

// Driver Code 
int main() 
{ 
	int ar1[] = {1, 12, 15, 26, 38}; 
	int ar2[] = {2, 13, 17, 30, 45}; 

	int n1 = sizeof(ar1) / sizeof(ar1[0]); 
	int n2 = sizeof(ar2) / sizeof(ar2[0]); 
	if (n1 == n2) 
		cout << "Median is "
			<< getMedian(ar1,0,n1-1,ar2,0,n2-1) ; 
	else
		cout << "Doesn't work for arrays"
			<< " of unequal size" ; 
	getchar(); 
	return 0; 
} 

// time  O(n)
