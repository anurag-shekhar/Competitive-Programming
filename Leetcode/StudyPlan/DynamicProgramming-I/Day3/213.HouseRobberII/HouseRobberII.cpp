/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : HouseRobberII.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    int helper(vector<int> nums, int start, int end)
    {
        if(end < start)
            return 0;
        if(end== start)
            return nums[start];
            
        int first = 0, second = 0, temp;
        for(int i = start; i<=end; i++)
        {
            if(i == start)
                temp = nums[i];
            else 
                temp = max(first + nums[i], second);
            first = second;
            second = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(helper(nums, 2, n-2) + nums[0], helper(nums, 1, n-1));
    }
};