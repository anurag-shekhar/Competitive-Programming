/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaxAreaofIsland.cpp
 * Created on : Tue Jun 01 2021
 ****************************************************************
 */

class Solution {
public:
    int r,c;
    bool isValid(int x, int y)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(!grid[x][y])
           return 0;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        grid[x][y] = 0;
        int count = 1;
        for(int i = 0; i<4; i++)
        {
            if(isValid(x+dx[i], y+dy[i]))
            {
                count += dfs(grid,x+dx[i], y+dy[i]);
            }
        }
        
       return count;
        
    }
        
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        int res = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                res = max(res, dfs(grid,i,j));
            }
        }
        return res;
    }
};
