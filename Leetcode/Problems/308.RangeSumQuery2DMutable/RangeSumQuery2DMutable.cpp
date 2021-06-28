/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RangeSumQuery2DMutable.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

class NumMatrix {
public:
    vector<vector<int> > mat;
    int r,c;
    
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        r = matrix.size();
        c = matrix[0].size();
        mat = matrix;
        for(int i = 0; i<r; i++)
        {
            for(int j = 1; j<c; j++)
            {
                mat[i][j] += mat[i][j-1];
            }
        }
    }
    
    void update(int row, int col, int val) {
        
        int originalVal = mat[row][col];
        if(col!=0)
            originalVal -= mat[row][col-1];
        
        int diff = val - originalVal;
        for(int i = col; i<c; i++)
        {
            mat[row][i] += diff;    
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        
        for(int i = row1; i<= row2; i++)
        {
            sum += mat[i][col2];
            if(col1!=0)
                sum -= mat[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
