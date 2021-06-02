/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumAreaRectangle.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    
   
    int minAreaRect(vector<vector<int>>& points) {
        
        
        map<int, set<int> > X;
        
        for(auto p : points)
            X[p[0]].insert(p[1]);
        
        int n = points.size();
        int res = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                
                if(X[points[i][0]].count(points[j][1]) && X[points[j][0]].count(points[i][1]))
                    res = min(res, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]) ) ;
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};
