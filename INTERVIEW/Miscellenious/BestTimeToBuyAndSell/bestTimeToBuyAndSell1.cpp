// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/781511/Easy-%3A-C%2B%2B-CODE-with-*-comments-*-to-understand-the-logic

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector < int > & prices) {
        if(prices.size()==0)
            return 0;
        int mini = INT_MAX;
        int maxi = 0;
      for(int i = 0; i < prices.size();i++)
        {
		
            //check if the current value is lesser than the minimum we've seen so far
            if(prices[i] < mini)
                mini = prices[i]; // Then update if yes
            
/*if the element is not the smallest as per the "if" condition , we further check if the (same element - mini) > maxi ,if yes we store that in maxi, or else we continue */
            else
            {
                maxi = max(maxi, prices[i]-mini);
            }
        }
        // the maximum profit will be stored in maxi
        return maxi;
        
    }
};