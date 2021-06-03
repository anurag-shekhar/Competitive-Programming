/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 165_optimised.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

bool solve(vector<vector<int>>& matrix, int target) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    
    int i = 0, j =c-1;
    while(i<r && j>=0)
    {
        if(matrix[i][j] >  target)
            j--;
        else if(matrix[i][j] <  target)
            i++;
        else 
            return true;    
    }
    return false;
}
