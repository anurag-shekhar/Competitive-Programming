/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReshapeTheMatrix.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        vector<vector<int> > res(r, vector<int> (c));
        int m = mat.size();
        int n = mat[0].size();
        
        if(r*c != m*n)
            return mat;
        int x = 0, y = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                res[x][y] = mat[i][j];
                y++;
                if(y==c)
                {
                    x++;
                    y=0;
                }
                    
            }
        }
        return res;
    }
};