/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumDistanceToTheTargetElement.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int res = INT_MAX;
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
        {
            if(nums[i]==target)
                res = min(abs(i-start), res);
        }
        return res;
    }
};
