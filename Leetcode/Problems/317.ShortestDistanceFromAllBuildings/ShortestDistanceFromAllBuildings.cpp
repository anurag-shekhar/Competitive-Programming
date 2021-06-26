/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ShortestDistanceFromAllBuildings.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int> > reach, dist;
    int r,c;
    bool isValid(int x, int y)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    
    void bfs(int X, int Y, vector<vector<int>>& grid)
    {
        queue<vector<int > > q;
        q.push({X,Y,0});
        vector<vector<bool> > visited = vector<vector<bool> > (r,vector<bool>(c,false));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(!q.empty())
        {
            vector<int> pt = q.front();
            q.pop();
            if(visited[pt[0]][pt[1]])
                continue;
            if(grid[pt[0]][pt[1]] == 0)
            {
                visited[pt[0]][pt[1]] = true;
                dist[pt[0]][pt[1]] += pt[2];
                reach[pt[0]][pt[1]]++;
            }
            for(int k = 0; k<4; k++)
            {
                int x = pt[0] + dx[k];
                int y = pt[1] + dy[k];
                if(isValid(x,y) && grid[x][y]==0)
                    q.push({x,y,pt[2]+1});
            }
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        
        r = grid.size(); 
        c = grid[0].size();
        reach = vector<vector<int> > (r,vector<int>(c,0));
        dist = vector<vector<int> > (r,vector<int>(c,0));
        
        int totalBuilding = 0;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    bfs(i,j,grid);
                    totalBuilding++;
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(reach[i][j]==totalBuilding)
                {
                    res = min(res, dist[i][j]);
                }
            }
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
