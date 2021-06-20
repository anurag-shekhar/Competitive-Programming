/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ToeplitzMatrix.cpp
 * Created on : Sun Jun 20 2021
 ****************************************************************
 */

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(i-1 >=0 && j-1>=0)
                {
                    if(matrix[i-1][j-1] != matrix[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};
