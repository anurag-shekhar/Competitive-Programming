/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FirstMissingPositive.cpp
 * Created on : Mon Jul 05 2021
 ****************************************************************
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        bool contain1 = false;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 1)
                contain1 = true;
            
            if(nums[i] < 1 || nums[i] > n)
                nums[i] = 1;
        }
        
        if(!contain1)
            return 1;
        
        for(int i = 0; i<n; i++)
        {
            if(nums[abs(nums[i])%n] > 0)
                nums[abs(nums[i])%n] *= -1;
        }
        
        for(int i = 1; i<=n; i++)
        {
            if(nums[i%n] > 0)
                return i;
        }
        return n+1;
    }
};
