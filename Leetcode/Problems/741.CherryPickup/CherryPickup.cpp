/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CherryPickup.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    int r,c;
    bool isValid(int x, int y,vector<vector<int>>& grid)
    {
        if(x>=0 && y>=0 && x<r && y<c && grid[x][y]!=-1)
            return true;
        return false;
    }
    int traverse(vector<vector<int>>& grid,  vector<vector<vector<int> > > &dp, int r1, int c1, int c2)
    {
        int r2 = r1 + c1 - c2;
        if(!isValid(r1,c1,grid) || !isValid(r2,c2,grid)) return INT_MIN;
        
        if(dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        if(r1==r-1 && c1==c-1)
            return grid[r1][c1];
        int ans = grid[r1][c1];
        if(r1!=r2) ans += grid[r2][c2];
        
        int res = traverse(grid, dp, r1+1,c1,c2);
        res = max(res , traverse(grid, dp, r1+1,c1,c2+1));
        res = max(res , traverse(grid, dp, r1,c1+1,c2));
        res = max(res , traverse(grid, dp, r1,c1+1,c2+1));
        
        ans += res;
        
        return dp[r1][c1][c2] = ans;
        
        
    } 
    int cherryPickup(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        vector<vector<vector<int> > > dp(r,vector<vector<int> > (c,vector<int> (c,-1)));
        
        return max(0,traverse(grid, dp, 0,0,0));
    }
};

/*
r1+1, c1 , c2
r1, c1+1, c2
r1, c1+1, c2+1
r1+1, c1, c2+1
 */   
