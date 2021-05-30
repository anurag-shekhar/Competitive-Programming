/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimizeMaximumPairSumInArray.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin() ,nums.end());
        
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<(n/2) ; i++)
        {
            sum = max(sum, nums[i] + nums[n-1-i]);
        }
        return sum;
        
    }
};
