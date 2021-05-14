/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 141.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

bool solve(vector<vector<int>>& matrix) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    for(int i = 1-r; i<c; i++)
    {
        for(int j = 0; i+j<min(r,c); j++)
        {
            int x = j; 
            int y = i+j;
            if(x>0 && y>0 && y<c && x<r)
            {
                if(matrix[x][y] != matrix[x-1][y-1])
                    return false;
            }
        }        
    }
    return true;
}
