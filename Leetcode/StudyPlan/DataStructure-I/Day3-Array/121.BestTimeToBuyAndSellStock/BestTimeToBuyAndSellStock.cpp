/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStock.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        
        int buyIdx = 0;
        for(int i = 0; i<prices.size(); i++)
        {
            if(prices[buyIdx] > prices[i])
                buyIdx = i;
            else 
                profit = max(profit, prices[i] - prices[buyIdx]);
        }
        return profit;
    }
};