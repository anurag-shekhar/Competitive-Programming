/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RunningSumOf1dArray.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        for(int i=1; i<nums.size(); i++)
            nums[i] += nums[i-1];
        return nums;
    }
};
