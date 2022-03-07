/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BestSightseeingPair.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int res = 0;
        int prev = values[0];
        
        int n = values.size();
        for(int i = 1; i<n ;i++)
        {
            res = max(res, values[i] - i + prev);
            prev = max(prev, values[i] + i);
        }
        return res;
    }
};
