/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Combinations.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

class Solution {
public:
    void backtrack(int n,vector<int> local, vector<vector<int> > &res, int k, int val)
    {
        if(local.size()==k)
        {
            res.push_back(local);
            return; 
        }
        for(int i = val; i<=n; i++)
        {
            local.push_back(i);
            backtrack(n, local, res, k, i+1);
            local.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        backtrack(n, {}, res, k, 1 );
        return res;
    }
};
