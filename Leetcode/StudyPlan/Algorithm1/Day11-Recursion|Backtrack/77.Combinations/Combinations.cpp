/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Combinations.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    void backtrack(vector<vector<int> > &result, vector<int> local, int itemLeft, int start, int n)
    {
        if(itemLeft==0)
        {
            result.push_back(local);
            return;
        }
        for(int i = start; i<=n; i++)
        {
            local.push_back(i);
            backtrack(result, local, itemLeft-1, i+1, n);
            local.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int> > result;
        backtrack(result, {}, k, 1, n);
        return result;
    }
};