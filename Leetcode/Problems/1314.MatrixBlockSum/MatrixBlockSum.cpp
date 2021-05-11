/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MatrixBlockSum.cpp
 * Created on : Tue May 11 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int> > res(r,vector<int> (c));
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(i-1 >= 0)
                    mat[i][j] += mat[i-1][j];
                if(j-1 >= 0)
                    mat[i][j] += mat[i][j-1];
                if(j-1 >= 0 && i-1 >= 0)
                    mat[i][j] -= mat[i-1][j-1];  
                
                              
            }
        }
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {     
                res[i][j] = mat[min(i+k,r-1)][min(j+k, c-1)];
                
                if(i-k-1 >=0)
                    res[i][j] -= mat[i-k-1][min(j+k, c-1)];
                if(j-k-1 >=0)
                    res[i][j] -= mat[min(i+k,r-1)][j-k-1];
                
                if(j-k-1 >=0 && i-k-1 >=0)
                    res[i][j] += mat[i-k-1][j-k-1];  
            }
        }   
        return res;
    }
};
