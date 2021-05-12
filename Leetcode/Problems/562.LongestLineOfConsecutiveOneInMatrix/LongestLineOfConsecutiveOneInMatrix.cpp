/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestLineOfConsecutiveOneInMatrix.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
           
        int prefixSum[r][c][4];
        
        int res =0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                for(int k = 0; k<4; k++)
                    prefixSum[i][j][k] = mat[i][j];
                
                if(mat[i][j])
                {
                    if(i>0 )
                        prefixSum[i][j][0] += prefixSum[i-1][j][0];
                    if(j>0)
                        prefixSum[i][j][1] += prefixSum[i][j-1][1];
                    if(j>0 && i>0)
                        prefixSum[i][j][2] += prefixSum[i-1][j-1][2];
                    if(i>0 && j<c-1)
                        prefixSum[i][j][3] += prefixSum[i-1][j+1][3];
                }
                for(int k = 0; k<4; k++)
                    res = max(res,prefixSum[i][j][k]);
            }
        }
        return res;    
    }
};
