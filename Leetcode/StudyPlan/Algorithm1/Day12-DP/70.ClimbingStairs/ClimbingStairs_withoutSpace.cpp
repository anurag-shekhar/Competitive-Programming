/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ClimbingStairs_withoutSpace.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

class Solution {
public:
    int helper(vector<int> dp, int n) {
        if(n>=0 && n<=1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = climbStairs(n-1) + climbStairs(n-2);   
        return dp[n];
    }
    int climbStairs(int n) {
        //TLE
        // vector<int> dp(n+1, -1);    
        // return helper(dp, n);
        
        //Fibo Method
        int first = 1; 
        int second = 1;
        int temp;
        for(int i = 2; i<=n; i++) {
            temp = second;
            second += first;
            first = temp;
        }
        return second;
    }
};