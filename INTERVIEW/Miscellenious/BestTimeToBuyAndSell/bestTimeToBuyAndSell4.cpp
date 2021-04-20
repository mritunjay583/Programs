#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1 || k<1)
            return 0;
        
        if(k>=n/2){  // number of transaction is greater than k then quesiton is converted to infinte transactions
            int ans=0;
            for(int i=1;i<n;i++){
                ans+=max(prices[i]-prices[i-1],0);
            }
            return ans;
        }
        
        vector<int> buy(k,INT_MIN);  //see this initialization very carefull
        vector<int> sell(k,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(j==0)
                    buy[j]=max(buy[j],-prices[i]);
                else
                    buy[j]=max(buy[j],sell[j-1]-prices[i]);
                
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        return *max_element(sell.begin(),sell.end());
    }
};