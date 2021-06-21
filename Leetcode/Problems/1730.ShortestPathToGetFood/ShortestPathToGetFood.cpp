/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ShortestPathToGetFood.cpp
 * Created on : Mon Jun 21 2021
 ****************************************************************
 */

class Solution {
public:
    int r, c;
    bool isValid(int x, int y, vector<vector<char>>& grid)
    {
        if(x>=0 && y>=0 && x<r && y<c && grid[x][y]!='X')
            return true;
        return false;
    }
    int getFood(vector<vector<char>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        vector<int> dx = {1, -1,0, 0};
        vector<int> dy = { 0, 0,1,-1};
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        
        
        queue<vector<int> > q;
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j]=='*')
                {
                    visited[i][j] = true;
                    q.push({i,j,0});
                    break;
                }
            }
        }
        
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            if(grid[cell[0]][cell[1]] == '#')
                return cell[2];
            for(int i = 0; i<4; i++)
            {
                int x = cell[0]+dx[i];
                int y = cell[1]+dy[i];
                if(isValid(x,y,grid) && !visited[x][y])
                {
                    visited[x][y] = true;
                    q.push({x, y, cell[2]+1});
                }
            }
        }
        return -1;
    }
};
