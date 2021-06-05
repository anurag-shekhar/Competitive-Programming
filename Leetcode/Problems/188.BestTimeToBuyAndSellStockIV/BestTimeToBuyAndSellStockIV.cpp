/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestTimeToBuyAndSellStockIV.cpp
 * Created on : Sat Jun 05 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        
            
        int n = prices.size();
        if(k==0 || n==0)
            return 0;
            
        vector<vector<int> > dp(k+1, vector<int> (n,0));
        
        for(int i = 1; i<=k; i++)
        {
            int maxVal = dp[i-1][0] - prices[0];
            for(int j = 1; j<n; j++)
            {
                dp[i][j] = max(dp[i][j-1], prices[j] + maxVal);
                maxVal = max(maxVal, dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][n-1];
        
    }
};

/*

1 2 3 4 5 2 3 4 5 6 4 5 6 7
^.       ^  ^     ^ ^.    ^
si       ei si    ej
4 4 3   


peaks[] = {a ,b ,c ,d}
a[i-1] =< a[i] && a[i] > a[i+1]
                                /
                            /
                        /
                      /
            / --------
        /        
    /
/
*/
