/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReshapeTheMatrix.cpp
 * Created on : Mon Jul 05 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c)
            return mat;
        
        vector<vector<int> > res(r, vector<int> (c));
        
        int resRow = 0, resCol = 0, inputRow = 0, inputCol = 0;
        for(int i = 0; i<r*c; i++)
        {
            if(inputCol == n)
            {
                inputCol = 0;
                inputRow++;
            }
            if(resCol == c)
            {
                resCol = 0;
                resRow++;
            }
            
            res[resRow][resCol] = mat[inputRow][inputCol];
            resCol++;
            inputCol++;
        }
        return res;
    }
};
