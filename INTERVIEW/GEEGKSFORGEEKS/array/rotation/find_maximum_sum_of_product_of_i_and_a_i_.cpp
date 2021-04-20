//Find maximum value of Sum( i*arr[i]) with only 
//rotations on given array allowed

// method to calculate sum of i*a[i] of next rotation 
//from current value

// next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1] * (n-1);

// next_val = Value of &Sum;i*arr[i] after one rotation.
// curr_val = Current value of &Sum;i*arr[i] 
// cum_sum = Sum of all array elements, i.e., &Sum;arr[i].
#include<bits/stdc++.h>

using namespace std;

int maximum_sum(const vector<int> &v)
{
    // initial condition 
    int cum_sum=accumulate(v.begin(),v.end(),0);
    int curr_val=0;
    for(int i=0;i<v.size();i++)curr_val+=(i*v[i]);

    int mx=curr_val;
    for(int i=1;i<v.size();i++)
    {
        int next_val=curr_val-(cum_sum-v[i-1])+v[i-1]*(v.size()-1);
        curr_val=next_val;
        mx=max(mx,curr_val);
    }
    return mx;
}

int main()
{
    vector<int> v{8,3,1,2};
    cout<<maximum_sum(v);   
}