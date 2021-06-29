/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaxConsecutiveOnesIII.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        int left = 0, right = 0;
        int numZeros = 0;
        int res = 0;
        while(right<n)
        {
            if(numZeros <= k)
            {
                if(nums[right] == 0)
                    numZeros++;
                right++;
                if(numZeros <= k)
                   res = max(res, right- left); 
            }
            else 
            {
                if(nums[left] == 0)
                    numZeros--;
                left++;
            }
        }
        return res;
    }
};
