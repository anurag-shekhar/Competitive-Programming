/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Subsets.cpp
 * Created on : Mon Oct 04 2021
 ****************************************************************
 */

class Solution {
public:
    
    void backtrack(vector<vector<int> > &res, vector<int> local, vector<int>& nums, int idx)
    {
        res.push_back(local);
        if(idx == nums.size())
            return;
        
        for(int i = idx; i<nums.size(); i++)
        {
            local.push_back(nums[i]);
            backtrack(res, local, nums, i+1);
            local.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(res, {}, nums, 0);
        return res;
    }
};
