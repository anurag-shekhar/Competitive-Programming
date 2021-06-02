/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountSquareSubmatricesWithAllOnes.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int res = 0;
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(matrix[i][j]==0)
                    continue;

               if(i!=0 && j!=0) 
                    matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i-1][j],matrix[i][j-1]));
                
                res += matrix[i][j];
            }
        }
        
        return res;
    }
};
