/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MergeTripletsToFormTargetTriplet.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > filter(vector<vector<int>>& triplets, int target, int pos)
    {
        vector<vector<int>> res;
        
        for(auto v : triplets)
        {
            if(v[pos] <= target)
                res.push_back(v);
        }
        return res;
            
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<vector<int>> res = filter(triplets, target[0], 0);
        res = filter(res, target[1], 1);
        res = filter(res, target[2], 2);
        
        vector<int> check(3,INT_MIN);
        for(auto v : res)
        {
            check[0] = max(v[0], check[0]);
            check[1] = max(v[1], check[1]);
            check[2] = max(v[2], check[2]);
        }
        if(check==target)
            return true;
        return false;
    }
};
