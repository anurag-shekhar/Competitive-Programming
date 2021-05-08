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
