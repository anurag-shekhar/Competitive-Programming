/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumAscendingSubarraySum.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int res = nums[0];
        int sum = nums[0];
        for(int i = 1; i<nums.size();i++){
            if(nums[i-1]<nums[i])
                sum+=nums[i];
            else 
                sum = nums[i];
            res = max(sum,res);
        }
        return res;
            
    }
};
