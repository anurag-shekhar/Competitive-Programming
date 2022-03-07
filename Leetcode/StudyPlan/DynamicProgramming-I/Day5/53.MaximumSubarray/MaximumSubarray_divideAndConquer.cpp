/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumSubarray_divideAndConquer.cpp
 * Created on : Mon May 31 2021
 ****************************************************************
 */

class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return INT_MIN;
        
        int mid = (right-left)/2 + left;
        int lmax = binary_search(nums, left, mid-1);
        int rmax = binary_search(nums, mid+1, right);
        
        int lsum = 0, rsum = 0;
        for(int i = mid-1, sum = 0; i>=left; i--)
        {
            sum += nums[i];
            lsum = max(lsum, sum);
        }
        for(int i = mid+1, sum = 0; i<=right; i++)
        {
            sum += nums[i];
            rsum = max(rsum, sum);
        }
        return max(max(lmax, rmax), lsum+rsum+nums[mid]); 
    }
    
    int maxSubArray(vector<int>& nums) {
        return binary_search(nums, 0, nums.size()-1);
    }
};
