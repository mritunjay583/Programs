#include<bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int prev_max=nums[0];
        int global_max=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int x=nums[i];
            int cur_max=max(prev_max+x,x);
            if(global_max<cur_max)
            {
                global_max=cur_max;
            }
            prev_max=cur_max;
        }
        return global_max;
        
    }

int main()
{
    vector<int> v{1 ,1 ,1, -1, -1, -1, -1, 1, 1, 1};
    cout<<maxSubArray(v);
}