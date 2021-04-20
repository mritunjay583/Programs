// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        
        vector<int> leftProfit(prices.size(),0); //calculate profit for each index from left to right
        int minSoFar=prices[0];

        for(int i=1;i<prices.size();i++){
            leftProfit[i]=max(leftProfit[i-1],prices[i]-minSoFar);
            minSoFar=min(minSoFar,prices[i]);
        }
        
        vector<int> rightProfit(prices.size(),0);//calculate profit for each index form right to left

        int maxSoFar=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            rightProfit[i]=max(rightProfit[i+1],maxSoFar-prices[i]);
            maxSoFar=max(maxSoFar,prices[i]);
        }
        int pro=0;
        for(int i=1;i<prices.size()-1;i++){ //now calcualte profit for 0 to i and i+1 to n
            pro=max(pro,leftProfit[i]+rightProfit[i+1]);
        }

        return max(pro,leftProfit[prices.size()-1]); //return max(excatly two transaction,excatly one transaction)

    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        int fb=INT_MIN;//let the first buy is buy big so i have due of large amount
        int fs=0;  //we have not selled yet so first sell is of 0
        int sb=INT_MIN; //same as first buy
        int ss=0; //same as first sell
        for(int i=0;i<prices.size();i++){
            fb=max(fb,0-prices[i]);  //we have to minimise first buy or maximize -due
            fs=max(fs,fb+prices[i]); //we have to maximize first sell and if i have -fb money so net left amount after first sell is fb+prices
            sb=max(sb,fs-prices[i]); //now money after second buy is fs-peices[i]
            ss=max(ss,sb+prices[i]); //money afer second sell is sb+prices[i]
        }
        return max(fs,ss);
    }
};