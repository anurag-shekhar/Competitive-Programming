/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UniqueBinarySearchTrees.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int numTrees(int n) {
        
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            int l = 0, r= i-1;
            while(r>=0)
            {
                dp[i] += (dp[l]*dp[r]);
                l++;r--;
            }
        }
        return dp[n];
    }
};
