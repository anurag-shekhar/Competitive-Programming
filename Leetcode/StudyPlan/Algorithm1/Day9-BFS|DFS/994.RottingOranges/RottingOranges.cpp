/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RottingOranges.cpp
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
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        queue<vector<int> > q;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0,0,-1,1};
        
        int freshOrange = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j,0});
                else if(grid[i][j] == 1)
                    freshOrange++;
            }
        }
        
        int time = 0;
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            time = max(time, cell[2]);
            
            for(int i = 0; i<4; i++)
            {
                int x = cell[0] + dx[i];
                int y = cell[1] + dy[i];
                
                if(isValid(x,y,r,c) && grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    q.push({x,y,cell[2]+1});
                    freshOrange--;
                }
                    
            }
        }
        if(freshOrange != 0)
            return -1;
        return time;
        
        
    }
};