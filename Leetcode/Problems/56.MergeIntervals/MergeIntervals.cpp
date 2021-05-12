/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MergeIntervals.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]))
            return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& A) {
        
        int n = A.size();
        sort(A.begin(),A.end(),compare);
        vector<vector<int> > res;
        res.push_back(A[0]);
        for(int i = 1; i<n; i++)
        {
            if(res.back()[1] < A[i][0])
                res.push_back(A[i]);
            else
                res[res.size()-1][1] = max(A[i][1],res[res.size()-1][1]);
        }
        return res;
            
    }
};
