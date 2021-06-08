/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Permutations.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int> &nums, int pos)
    {
        int n = nums.size();
        if(pos ==n)
        {
            res.push_back(nums);
            return;
        }
        for(int i = pos; i<n; i++)
        {
            swap(nums[i], nums[pos]);
            backtrack(nums, pos+1);
        }
        for(int i = pos+1; i<n; i++)
            swap(nums[i-1], nums[i]);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        
        backtrack(nums, 0);
        return res;
    }
};

/*
1 2 3 4

2 1 3 4

3 1 2 4 
4 1 2 3
*/
