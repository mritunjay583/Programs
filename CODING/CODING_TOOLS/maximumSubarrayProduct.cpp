#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums) 
{
        int prev_max=nums[0];
        int prev_min=nums[0];
        int global_max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int x=nums[i];
            int cur_max=max(prev_max*x,max(prev_min*x,x));
            int cur_min=min(prev_max*x,min(prev_min*x,x));
            if(global_max<cur_max)
                global_max=cur_max;
            prev_max=cur_max;
            prev_min=cur_min;
        }
        return global_max;
}

int main()
{
    vector<int> v{2,3,-2,4};
    cout<<maxProduct(v);
}