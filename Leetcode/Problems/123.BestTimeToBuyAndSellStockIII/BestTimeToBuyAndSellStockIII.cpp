/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStockIII.cpp
 * Created on : Sat Jun 05 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(3, vector<int> (n,0));
        
        for(int i = 1; i<=2; i++)
        {
            int maxVal = dp[i-1][0] - prices[0];
            for(int j = 1; j<n; j++)
            {
                dp[i][j] = max(dp[i][j-1], prices[j] + maxVal);
                maxVal = max(maxVal, dp[i-1][j]-prices[j]);
            }
        }
        return dp[2][n-1];
    }
};
