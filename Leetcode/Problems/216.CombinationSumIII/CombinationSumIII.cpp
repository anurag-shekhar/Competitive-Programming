/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CombinationSumIII.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int> local, int n, int k, int val)
    {
        if(local.size()==k)
        {
            if(n==0)
                res.push_back(local);
            return;
        }
        for(int i = val; i<=9; i++)
        {
            local.push_back(i);
            backtrack(local, n-i, k, i+1);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        res.clear();
        backtrack({}, n, k, 1);
        return res;
        
    }
};
