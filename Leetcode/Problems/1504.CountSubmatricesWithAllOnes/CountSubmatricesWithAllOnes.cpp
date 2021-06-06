/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountSubmatricesWithAllOnes.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        for(int i=0; i<r; i++)
        {
            for(int j = 1 ; j<c; j++)
            {
                if(matrix[i][j])
                matrix[i][j]+=matrix[i][j-1]; 
            }
        }
        
        int totalMatrices = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                int res = INT_MAX;
                for(int k = i; k<r; k++)
                {
                    res = min(res, matrix[k][j]);
                    totalMatrices += res;
                }
            }
        }
        return totalMatrices;
        
    }
};
/*
1,0,1
1,1,0
1,1,0
    
1,0,1
2 2 0
3 4
    
0 1 1 0
0 1 1 1
1 1 1 0

0 1 2 0
0 2 4 3
1 4
*/  
    
