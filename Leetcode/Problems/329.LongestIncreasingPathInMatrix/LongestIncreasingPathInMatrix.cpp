/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestIncreasingPathInMatrix.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool isValid(int i, int j, int r, int c)
    {
        if(0<=i && 0<=j && j<c && i<r)
            return true;
        return false;
    }
    int dfs(vector<vector<int> > &dp, vector<vector<int>>& matrix, int i, int j, int r, int c)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        int len = 0;
        for(int k = 0; k<4; k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];
            
            if(isValid(x, y, r, c))
            {
                if(matrix[x][y] > matrix[i][j])
                    len = max(len, dfs(dp,matrix,x,y,r,c));
            }
        }
        dp[i][j] = len+1;
        return dp[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int> > dp(r,vector<int>(c,-1));
        
        int res = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                res = max(res, dfs(dp,matrix, i,j,r,c));
            }
        }
        
        return res;
        
    }
};
