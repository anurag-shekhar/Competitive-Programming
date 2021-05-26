/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestContinuousSubarrayWithAbsoluteDiffLessThanOrEqualToLimit.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        deque<int> min_dq, max_dq;
        int left = 0, right = 0;
        int res = 0;
        while(right<n)
        {
            while(!min_dq.empty() && nums[min_dq.back()] > nums[right])
                min_dq.pop_back();
            min_dq.push_back(right);
            
            while(!max_dq.empty() && nums[max_dq.back()] < nums[right])
                max_dq.pop_back();
            max_dq.push_back(right);
            
            while(max_dq.front() < left) max_dq.pop_front();
            while(min_dq.front() < left) min_dq.pop_front();
            
            if(abs(nums[max_dq.front()] - nums[min_dq.front()]) <= limit)
            {   
                right++;
                res = max(res, right-left);
            }    
            else 
                left++;
        }
        return res;
    }
};



