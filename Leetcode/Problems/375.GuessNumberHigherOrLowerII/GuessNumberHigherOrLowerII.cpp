/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GuessNumberHigherOrLowerII.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > dp;
    int solve(int left, int right)
    {
        if(left >= right)
            return 0;
        if(dp[left][right]!=0)
            return dp[left][right];
        
        int res = INT_MAX;
        for(int i = left; i<=right; i++)
        {
            res = min(res, i+max(solve(left, i-1),solve(i+1, right)));
        }
        dp[left][right] = res;
        return res;
    }
    int getMoneyAmount(int n) {

        dp = vector<vector<int> >(n+1, vector<int> (n+1, 0));
        solve(1, n);
        return dp[1][n];
    }
};


/*
     
*/          
