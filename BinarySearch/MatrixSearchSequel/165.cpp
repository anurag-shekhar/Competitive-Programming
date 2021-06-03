/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 165.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

int binary_search(vector<int> &A, int left, int right, int target)
{
    while(left <= right)
    {
        int mid = (right-left)/2 + left;

        if(A[mid] == target)
            return mid;
        else if(A[mid] > target)
            right = mid-1;
        else 
            left = mid+1;  
    }
    return -1;
}
bool solve(vector<vector<int>>& matrix, int target) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    
    for(int i = 0; i<r; i++)
    {
        if(matrix[i][0] <= target && matrix[i][c-1]>=target)
        {
            int val = binary_search(matrix[i], 0, c-1, target);
            if(val != -1)
                return true;
        }
    }
    return false;
}
