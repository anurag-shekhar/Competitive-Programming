/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DetermineWhetherMatrixCanBeObtainedByRotation.cpp
 * Created on : Tue Jun 08 2021
 ****************************************************************
 */

class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        
        for(int i = 0; i<(n+1)/2; i++)
        {
            for(int j = i; j<(n-i-1); j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
    
    bool check(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int n = mat.size();
        for(int i = 0; i<n; i++)
        {
            if(mat[i] != target[i])
                return false;
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(check(mat,target))
            return true;
        rotate(mat);
        if(check(mat,target))
            return true;
        rotate(mat);
        if(check(mat,target))
            return true;
        rotate(mat);
        if(check(mat,target))
            return true;
        rotate(mat);
        if(check(mat,target))
            return true;
        return false;
    }
};
