/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStock.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = 0, sell = 0;
        int maxSum = 0;
        while(sell<prices.size())
        {
            if(prices[sell] <= prices[buy])
            {
                buy = sell;
            }
             
            maxSum = max(maxSum, prices[sell] - prices[buy]);
            sell++;    
            
        }
        return maxSum;
        
    }
};
