#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<=1)
            return 0;
        int nostock=0;
        int onestock=-prices[0];
        for(int i=1;i<prices.size();i++){
            nostock=max(nostock,onestock+prices[i]-fee);
            onestock=max(onestock,nostock-prices[i]);
        }
        return nostock;
    }
};