/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumMatrixSum.cpp
 * Created on : Sat Aug 21 2021
 ****************************************************************
 */

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum = 0;
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        int smallNum = INT_MAX;
        int numOfNeg = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(matrix[i][j] < 0)
                    numOfNeg++;
                sum += abs(matrix[i][j]);
                
                smallNum = min(smallNum, abs(matrix[i][j]));    
            }
        }
        
        if(numOfNeg % 2)
            sum -= 2*smallNum;
        return sum;
    }
};
