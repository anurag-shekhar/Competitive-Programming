/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SpiralMatrix.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> res(r*c);
        
        int idx = 0;
        int up = 0, down = r-1;
        int left = 0, right = c-1;
        
        int n = r*c;
        while(idx<n)
        {
            for(int i = left; i<=right && idx<n; i++)
                res[idx++] = matrix[up][i];
            up++;
            
            for(int i = up; i<=down && idx<n; i++)
                res[idx++] = matrix[i][right];
            right--;
            
            for(int i = right; i>=left && idx<n; i--)
                res[idx++] = matrix[down][i];
            down--;
            
            for(int i = down; i>=up && idx<n; i--)
                res[idx++] = matrix[i][left];
            left++;
        }
        return res;
    }
};
