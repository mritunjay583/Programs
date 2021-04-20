///////////////////////////////////////////////////////
//Maximum subarray problem can be solved in three differet way//
/////////////////////////////////////////////////////////////
#include<bits/stdc++.h>

using namespace std;


/////////////////////////////////
// complexity O(n)//////////////
///////////////////////////////

int max_subarray_sum(int a[],int size)
{
    int maxsofar=a[0];
    int maxi=0;
    for(int i=0;i<size;i++)
    {
        maxi=max(maxi+a[i],a[i]);
        maxsofar=max(maxsofar,maxi);
    }
    return maxsofar;
}

/////////////////////////////////////////
////////////////////////////////////////

int main()
{
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(a)/sizeof(a[0]);
    int result = max_subarray_sum(a,size);
    cout<<"maximum contigious subaray  sum = "<<result<<endl;
    
}