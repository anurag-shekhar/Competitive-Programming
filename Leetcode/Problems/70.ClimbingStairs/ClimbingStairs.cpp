/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ClimbingStairs.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */


class Solution {
public:
    int climbStairs(int n) {
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        vector<int> dp(n+1, 0);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
