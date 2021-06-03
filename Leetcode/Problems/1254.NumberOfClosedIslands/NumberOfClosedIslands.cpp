/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfClosedIslands.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    int r,c;
    int isValid(int x, int y)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(grid[x][y]==1)
            return;
        grid[x][y] = 1;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i = 0; i<4; i++)
        {
            if(isValid(x+dx[i], y+dy[i]))
            {
                dfs(grid,x+dx[i],y+dy[i]);
            }
        }
            
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        int count = 0;
        
        for(int i = 0; i <r; i++)
        {
            dfs(grid,i,0);
            dfs(grid,i,c-1);
        }
        for(int i = 0; i<c; i++)
        {
            dfs(grid,0,i);
            dfs(grid,r-1,i);
        }
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                    dfs(grid, i, j);
                }
                    
            }
        }
        return count;
    }
};
