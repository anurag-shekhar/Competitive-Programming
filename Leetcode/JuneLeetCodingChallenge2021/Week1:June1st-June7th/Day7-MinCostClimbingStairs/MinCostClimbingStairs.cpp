/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinCostClimbingStairs.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i = 2; i<=n; i++)
        {
            dp[i] = min(dp[i-1], dp[i-2]);
            if(i<n)
                dp[i] += cost[i];
        }
        return dp[n];
    }
};
