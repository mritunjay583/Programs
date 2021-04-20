// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){ //doing cummulative sum will give the answer
            if(prices[i]<prices[i+1]){
                profit+=(prices[i+1]-prices[i]);
            }
        }
        return profit;
    }
};