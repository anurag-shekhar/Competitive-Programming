/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KClosestPointsToOrigin.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if((a[0]*a[0] + a[1]*a[1]) <= (b[0]*b[0] + b[1]*b[1]))
            return true;
        return false;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(), points.end(), compare);
        
        vector<vector<int> > res;
        for(int i = 0; i<k; i++)
        {
            res.push_back(points[i]);
        }
        return res;
        
    }
};
