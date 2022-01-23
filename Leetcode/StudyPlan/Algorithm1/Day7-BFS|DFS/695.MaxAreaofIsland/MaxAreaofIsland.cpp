/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaxAreaofIsland.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    bool isValid(int x, int y, int r, int c)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    int helper(vector<vector<int>>& grid, int x, int y, int r, int c)
    {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        
        int area = 1; 
        grid[x][y] = 0;
        for(int k = 0; k<4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if(isValid(newX, newY, r, c) && grid[newX][newY] == 1)
                area += helper(grid, newX, newY, r, c);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        
        int r = grid.size();
        int c = grid[0].size();
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j] == 1)
                    res = max(res, helper(grid, i, j, r,c));
            }
        }
        return res;
    }
};