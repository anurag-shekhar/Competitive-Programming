/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumSubarray.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0],maxSum = nums[0];
        
        for(int i = 1; i<nums.size(); i++)
        {
            if(currSum + nums[i] < nums[i])
                currSum = nums[i];
            else 
                currSum += nums[i];
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
       
    }
};
