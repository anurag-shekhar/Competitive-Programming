/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumProductSubarray.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int res = nums[0];
        
        int n = nums.size();
        for(int i = 1; i<n; i++)
        {
            int curr = max(nums[i], max(max_so_far*nums[i] , min_so_far*nums[i]));
            min_so_far = min(nums[i], min(max_so_far*nums[i] , min_so_far*nums[i]));
            
            max_so_far = curr;
            res = max(res, max_so_far);
        }
        return res;
        
    }
};
