/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestIncreasingSubsequence.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i = 0; i<n; i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
                
                res = max(res, dp[i]);
                
            }
        }
        
        return res;
    }
};
/*
10 9 2 5 3 7 101 18
0  1 2 3 4 5   6  7

2 3 5 7 9 10 18 101
2 4 3 5 1 0  7.  6
*/
