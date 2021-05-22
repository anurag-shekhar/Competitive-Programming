/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CherryPickupII.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    int r,c;
    bool isValid(int y)
    {
        if(y>=0 && y<c)
            return true;
        return false;
    }
    
    int traverse(vector<vector<int>>& grid, vector<vector<vector<int> > > &dp, int r1, int c1, int c2)
    {
        if(!isValid(c1) || !isValid(c2)) return 0;
        if(dp[r1][c1][c2]!= -1) return dp[r1][c1][c2];
        
        int ans = grid[r1][c2];
        if(c1!=c2)
            ans = grid[r1][c1] + grid[r1][c2];
        
        if(r1 == r-1)
            return ans;
        
        int temp = 0;
        for(int i = -1; i<=1; i++)
            for(int j = -1; j<=1; j++)
                temp = max(temp, traverse(grid, dp, r1+1, c1+i, c2+j));                
         
        ans += temp;
        return dp[r1][c1][c2] = ans;     
    }
    int cherryPickup(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        vector<vector<vector<int> > > dp(r,vector<vector<int> > (c, vector<int> (c,-1) ) );
        
        return traverse(grid, dp, 0,0,c-1);
    }
};
