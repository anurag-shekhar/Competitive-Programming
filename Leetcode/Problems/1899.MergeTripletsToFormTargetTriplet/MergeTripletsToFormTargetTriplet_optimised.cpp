/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MergeTripletsToFormTargetTriplet_optimised.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
            
        vector<int> check(3,INT_MIN);
        for(auto v : triplets)
        {
            if(v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2])
            {
                check[0] = max(v[0], check[0]);
                check[1] = max(v[1], check[1]);
                check[2] = max(v[2], check[2]);
            }
        }
        if(check==target)
            return true;
        return false;
    }
};
