/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TwoSum.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> m;
        for(int i = 0; i<nums.size(); i++)
        {
            int check  = target - nums[i];
            auto itr = m.find(check);
            if(itr!=m.end())
                return {itr->second,i};
            m[nums[i]] = i;
        }
        return {};
        
    }
};
