/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumSizeSubarraySumEqualsK.cpp
 * Created on : Thu Sep 30 2021
 ****************************************************************
 */
 
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        int n = nums.size();
        int sum = 0;
        int res=0;
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
            
            if(sum == k)
                res = max(res, i+1);
            else 
            {
                int diff = sum - k;
                if(m.count(diff))
                    res = max(res, i - m[diff]);
            }
            if(!m.count(sum))
                m[sum] = i;
        }
        return res;
    }
};
