/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ShortestPathInGridWithObstaclesElimination.cpp
 * Created on : Mon Jun 21 2021
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
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int r = grid.size(); 
        int c = grid[0].size();
        vector<vector<vector<bool> > > visited(r, vector<vector<bool> > (c, vector<bool> (k+1,false)));
        
        queue<vector<int> > q;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        q.push({0,0,k,0});
        
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            if(cell[0] == r-1 && cell[1]==c-1)
                return cell[3];
            
            for(int k = 0; k<4; k++)
            {
                int x = cell[0]+dx[k];
                int y = cell[1]+dy[k];
                if(isValid(x,y,r,c))
                {
                    if(grid[x][y]==0 && !visited[x][y][cell[2]])
                    {
                        visited[x][y][cell[2]] = true;
                        q.push({x,y,cell[2], cell[3]+1});
                    }
                        
                    else if(grid[x][y]==1 && cell[2]-1 >=0 && !visited[x][y][cell[2]-1])
                    {
                        visited[x][y][cell[2]-1] = true;
                        q.push({x,y,cell[2]-1, cell[3]+1});
                    }
                        
                }
            }
        }
        return -1;
        
        
    }
};
