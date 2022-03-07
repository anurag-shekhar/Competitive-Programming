/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumSubarray.cpp
 * Created on : Mon Jan 10 2022
 ****************************************************************
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_so_far = nums[0];
        int curr_sum = nums[0];
        
        int n = nums.size();
        for(int i = 1; i<n; i++)
        {
            curr_sum += nums[i];
            if(curr_sum < nums[i])
                curr_sum = nums[i];
            max_so_far = max(curr_sum, max_so_far);
        }
        return max_so_far;
       
    }
};
