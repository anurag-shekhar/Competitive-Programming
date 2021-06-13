/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CombinationSumIV.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums, int target)
    {
        if(target <=0)
        {
            if(target==0)
                return 1;
            return 0;
        }
        if(dp[target]!=-1)
            return dp[target];
        
        dp[target] = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            dp[target] += helper(nums, target-nums[i]);
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        dp= vector<int>(target+1, -1);
        return helper(nums, target);
        
    }
};
