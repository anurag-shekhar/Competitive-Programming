/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumProductSubarray.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maximum = nums[0];
        int minimum = nums[0];
        int res = nums[0];
        int temp;
        int n = nums.size();
        for(int i = 1; i<n; i++)
        {
            temp = max(nums[i], max(maximum*nums[i], minimum*nums[i]));
            minimum = min(nums[i], min(maximum*nums[i], minimum*nums[i]));
            
            maximum = temp;
            res = max(maximum, res);
        }
        return res;
        
    }
};