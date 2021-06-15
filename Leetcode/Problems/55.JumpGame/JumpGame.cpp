/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGame.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        
        int n = nums.size();
        if(n==1)
            return true;
        vector<int> dp(n+1);
        if(nums[0] == 0)
            return false;
        dp[0] = 1;
        dp[1] = -1;
        
        for(int i = 0; i<n; i++)
        {
            if(i!=0)
                dp[i] += dp[i-1];
            if(dp[i]==0)
                continue;
            if(nums[i]!=0)
            {
                dp[i+1]++;
                dp[min(i+nums[i]+1, n)]--;
            }
        }
        return dp[n-1] > 0;
    }
};
