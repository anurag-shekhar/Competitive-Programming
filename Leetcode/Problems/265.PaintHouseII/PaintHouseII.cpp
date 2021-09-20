/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PaintHouseII.cpp
 * Created on : Mon Sep 20 2021
 ****************************************************************
 */

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        
        int n = costs.size();
        int k = costs[0].size();
        int res = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            int firstMin = INT_MAX, secondMin = INT_MAX;
            for(int j = 0; j<k; j++)
            {
                if(i!=0)
                    costs[i][j] += costs[i-1][j];
    
                if(i==n-1)
                    res = min(res, costs[i][j]);
                if(firstMin > costs[i][j])
                {
                    secondMin = firstMin;
                    firstMin = costs[i][j];
                }
                else if(secondMin > costs[i][j])
                {
                    secondMin = costs[i][j];
                }
            }
            for(int j = 0; j<k; j++)
            {
                if(costs[i][j] == firstMin)
                    costs[i][j] = secondMin;
                else 
                    costs[i][j] = firstMin; 
            }
        }
        return res;
    }
};
