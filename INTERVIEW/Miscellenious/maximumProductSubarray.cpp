// https://practice.geeksforgeeks.org/problems/maximum-product-subarray/0

#include <bits/stdc++.h>
#define mx 1000000007

using namespace std;
int maxProduct(vector<long long int> &nums)
{
    long long int prev_max = nums[0];
    long long int prev_min = nums[0];
    long long int global_max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        long long int x = nums[i];
        int cur_max = max((prev_max * x) % mx, max((prev_min * x) % mx, x));
        int cur_min = min((prev_max * x) % mx, min((prev_min * x) % mx, x));
        if (global_max < cur_max)
            global_max = cur_max;
        prev_max = cur_max;
        prev_min = cur_min;
    }
    return global_max;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> v(n);
        for (auto &x : v)
            cin >> x;
        cout << maxProduct(v) << endl;
    }
}


// sample input
// 3
// 5
// 6 -3 -10 0 2
// 6
// 2 3 4 5 -1 0 
// 10
// 8 -2 -2 0 8 0 -6 -8 -6 -1