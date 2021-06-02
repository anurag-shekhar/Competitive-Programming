/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindValidMatrixGivenRowAndColumnSums.cpp
 * Created on : Wed Jun 02 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int r = rowSum.size();
        int c = colSum.size();
        vector<vector<int> > res(r, vector<int> (c));

        for(int i=0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                res[i][j] = min(rowSum[i] , colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
        
    }
};
