/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BurstBalloons_2.cpp
 * Created on : Sun Jun 23 2024
 ****************************************************************
 */

class Solution {
public:

    int helper(vector<vector<long> > &dp, vector<int> &nums) {
        int n = nums.size();
        vector<int> A(1,1);

        for(int i = 0; i<n; i++) {
            A.push_back(nums[i]);
        }
        A.push_back(1);
        for(int j = 1; j<=n; j++) {
            for(int i=1; i+j-1<=n; i++) {
                int right = i+j-1;
                int left = i;
                for(int k = left; k<=right; k++) {    
                    long result = (long)A[k]*(long)A[left-1]*(long)A[right+1] + dp[left][k-1] + dp[k+1][right];
                    dp[left][right] = max(dp[left][right], result);
                }
            }
        }
        return dp[1][n];
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long> > dp(n+2, vector<long> (n+2, 0));
        return helper(dp, nums);
    }
};