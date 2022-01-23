/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Permutations.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    void backtrack(vector<vector<int> > &result, vector<int> &nums, int start, int n)
    {
        if(start == n)
        {
            result.push_back(nums);
            return;
        }
        for(int i = start; i<n; i++)
        {
            swap(nums[start], nums[i]);
            backtrack(result, nums, start+1, n);
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        
        backtrack(result, nums, 0, nums.size());
        return result;
    }
};