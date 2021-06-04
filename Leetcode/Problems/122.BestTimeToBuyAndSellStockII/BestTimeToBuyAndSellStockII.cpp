/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStockII.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int n = prices.size();
        int sellIdx = 1;
        
        while(sellIdx < n)
        {
            if(prices[sellIdx-1] <= prices[sellIdx])
            {
                profit += (prices[sellIdx] - prices[sellIdx-1]);
            }
            sellIdx++;
        }
        return profit;
        
    }
};
