// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
#include<bits/stdc++.h>
using namespace std;

void maximum_of_all_subarray_of_size_K(int a[],int n,int k)
{
    deque<int> q(k);
    int i=0;
    // put first k elements in deque
    while(i<k)
    {
        while(q.size()!=0 && a[i]>=a[q.back()])
            q.pop_back();
            
        q.push_back(i);
        i++;
    }
    while(i<n)
    {
        cout<<a[q.front()]<<" ";
        //pop elements from front whose value is less equal to i-k
        while((q.size()!=0) && (q.front()<=(i-k)))
            q.pop_front();
            
        while((q.size()!=0) && (a[q.back()]<=a[i]))
            q.pop_back();
            
        q.push_back(i);
        i++;
    }
    cout<<a[q.front()]<<" ";
    cout<<endl;
}
int main()
{
    int a[]={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n=sizeof(a)/sizeof(a[0]);
    int k=4;
    maximum_of_all_subarray_of_size_K(a,n,k);
}