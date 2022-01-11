/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TwoSum.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        int n = nums.size();
        
        for(int i = 0; i<n; i++)
        {
            int check = target - nums[i];
            if(m.count(check))
            {
                return {m[check], i};
            }
            m[nums[i]] = i;
        }
        return {0,0};
    }
};