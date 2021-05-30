/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SetMatrixZeroes.cpp
 * Created on : Mon May 31 2021
 ****************************************************************
 */

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        bool row = false, col = false;
        
        for(int i = 0; i<r; i++)
        { 
            for(int j = 0; j<c; j++)
            {
                if(matrix[i][j]==0)
                {
                    if(j==0)
                        col = true;
                    if(i==0)
                        row = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = r-1; i>=0; i--)
        {
            
            for(int j = c-1; j>=0; j--)
            {
                if(i==0 && row || j==0 && col)
                    matrix[i][j] = 0;  
                else if (i>0 && j>0 && (matrix[i][0]==0 || matrix[0][j]==0))
                    matrix[i][j] = 0;
            }
            
        }
    }
};
/*
[0,1,2,0]
[3,4,5,2]
[1,3,1,5]]


[0,0,3,0]
[0,0,7,8]
[0,10,11,12]
[0,14,15,0]
*/
