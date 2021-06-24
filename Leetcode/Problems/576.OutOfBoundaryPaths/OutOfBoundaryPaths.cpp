/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : OutOfBoundaryPaths.cpp
 * Created on : Thu Jun 24 2021
 ****************************************************************
 */

#define MOD 1000000007
class Solution {
public:
    vector<vector<vector<long> > > dp;
    int r,c;
    bool isValid(int x, int y)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    int dfs(int x, int y, int move)
    {
        if(move==0)
            return 0;
        if(dp[x][y][move] != -1)
            return dp[x][y][move];
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        dp[x][y][move] = 0;
        for(int k = 0; k<4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if(isValid(newX, newY))
            {
                dp[x][y][move] += dfs(newX, newY, move-1);
                dp[x][y][move] %= MOD;
            }
            else if(move == 1)
            {
                dp[x][y][move] += 1;
                dp[x][y][move] %= MOD;
            }
                
        }
        return dp[x][y][move];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m;
        c = n;
        dp = vector<vector<vector<long> > > (m, vector<vector<long> >(n, vector<long> (maxMove+1, -1)));
        long val = 0;
        
        for(int i = 0; i<=maxMove; i++)
        {
            val += dfs(startRow, startColumn, i);
            val %= MOD;
        }
        return val;
        
    }
};
