/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStockWithTransactionFee.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

    
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<vector<int> > dp(n, vector<int> (2,0));
        
        dp[0][0] = 0;
        dp[0][1] = 0-prices[0]-fee;
        
        for(int i = 1; i<n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][0] - prices[i] - fee, dp[i-1][1]);
        }
        return dp[n-1][0];
    }
};
