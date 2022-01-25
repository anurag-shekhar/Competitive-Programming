/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : Search2DMatrix.cpp
 * Created on : Tue Jan 25 2022
 ****************************************************************
 */

class Solution {
public:
    bool Bsearch(vector<vector<int>>& matrix,int n, int left, int right, int target)
    {
        if(left > right)
            return false;
        int mid = (left + right)/2;
        
        if(target == matrix[mid/n][mid%n])
            return true;
        else if(target < matrix[mid/n][mid%n])
            return Bsearch(matrix,n, left, mid-1, target);
        else 
            return Bsearch(matrix, n, mid+1, right, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        return Bsearch(matrix, n, 0,m*n-1, target);
    }
};
