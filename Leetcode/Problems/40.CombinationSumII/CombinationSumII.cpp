/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CombinationSumII.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

class Solution {
public:
    void backtrack(vector<int>& candidates,vector<int> local, vector<vector<int> > &res, int target, int idx)
    {
        if(target <= 0)
        {
            if(target ==0)
                res.push_back(local);
            return; 
        }
        int n=candidates.size();
        for(int i = idx; i<n; i++)
        {
            if(i>idx && candidates[i-1] == candidates[i])
                continue;
            local.push_back(candidates[i]);
            backtrack(candidates, local, res, target-candidates[i], i+1);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, {}, res, target, 0);
        return res;
    }
};
