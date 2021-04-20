#include<bits/stdc++.h>

using namespace std;

// when all elments are repeated 
// worst case performance will be O(n)

// so you can solve this problem using linear seach
    int count_rotations(vector<long long int> &v,int l,int r,int n)
    {
        if(l>r)
            return -1;
        int mid=(l+r)/2;
        if(mid+1<n && v[mid+1]<v[mid])
            return mid+1;
        else if(mid-1>=0 && v[mid-1]>v[mid])
            return mid;
        else if(v[mid]<v[r])
            return count_rotations(v,l,mid-1,n);
        else if(v[mid]>v[l])
            return count_rotations(v,mid+1,r,n);
        else
        {
            // you can see we aree calling function for both
            //halves
            int res1=count_rotations(v,l,mid-1,n);
            int res2=count_rotations(v,mid+1,r,n);
            if(res1==-1)
                return res2;
            return res1;
        }
        
        
    }

int main()
{
    vector<long long int> v{1,1,1,1,1,1,2,2,2,2,2,2,2};
    int res=count_rotations(v,0,v.size()-1,v.size());
    cout<<res+1<<endl;
}