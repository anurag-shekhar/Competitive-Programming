/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : HouseRobber.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        nums[1] = max(nums[1], nums[0]);
        
        for(int i = 2; i<n; i++)
        {
            nums[i] = max(nums[i] + nums[i-2], nums[i-1]);    
        }
        return nums[n-1];
        
    }
};