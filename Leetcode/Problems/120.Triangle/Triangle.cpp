/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Triangle.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<int> dp;
        dp = triangle[n-1];
        
        for(int i = n-2; i>=0; i--)
        {
            for(int j = 0; j<=i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
