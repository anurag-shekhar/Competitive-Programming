/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RangeSumQuery2DImmutable.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class NumMatrix {
public:
    vector<vector<int> > prefixMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        prefixMatrix = vector<vector<int> > (r,vector<int>(c));
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                prefixMatrix[i][j] = matrix[i][j];
                if(i-1 >=0)
                    prefixMatrix[i][j] += prefixMatrix[i-1][j];
                if(j-1>=0)
                    prefixMatrix[i][j] += prefixMatrix[i][j-1];
                if(i-1 >=0 && j-1>=0)
                     prefixMatrix[i][j] -= prefixMatrix[i-1][j-1];  
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = prefixMatrix[row2][col2];
        
        if(row1-1 >=0)
            sum -= prefixMatrix[row1-1][col2];
        
        if(col1-1 >=0)
            sum -= prefixMatrix[row2][col1-1];
        
        if(row1-1 >=0 && col1-1 >=0)
            sum += prefixMatrix[row1-1][col1-1];
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
