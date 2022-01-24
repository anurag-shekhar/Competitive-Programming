/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Triangle.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int r = triangle.size();
        int lastCol = triangle[r-1].size();
        
        if(r==1)
            return triangle[0][0];
        
        for(int i = r-2; i>=0; i--)
        {
            for(int j = 0; j<=i; j++)
            {
                triangle[i][j] += min(triangle[i+1][j] , triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
        
        
    }
};