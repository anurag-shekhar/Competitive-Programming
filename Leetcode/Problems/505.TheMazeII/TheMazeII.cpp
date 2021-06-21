/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TheMazeII.cpp
 * Created on : Mon Jun 21 2021
 ****************************************************************
 */

class Solution {
public:
    int r, c;
    bool isValid(int x, int y, vector<vector<int>>& maze)
    {
        if(x>=0 && y>=0 && x<r && y<c && maze[x][y]==0)
            return true;
        return false;
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        
        //BFS
        r = maze.size();
        c = maze[0].size();
        
        vector<int> dx = {0, 1, 0 , -1};
        vector<int> dy = { 1, 0,-1, 0};
        vector<vector<int> > visited(r,vector<int>(c,INT_MAX));
        
        
        queue<vector<int> > q;
        q.push({start[0], start[1],0,0});
        q.push({start[0], start[1],1,0});
        q.push({start[0], start[1],2,0});
        q.push({start[0], start[1],3,0});
        visited[start[0]][start[1]] = 0;
        int res = INT_MAX;
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            int x = cell[0];
            int y = cell[1];
            
            if(isValid(x+dx[cell[2]], y+dy[cell[2]], maze))
            {
                q.push({x+dx[cell[2]], y+dy[cell[2]], cell[2], cell[3]+1});
            }
            else 
            {
                
                if(x== destination[0]  && y == destination[1])
                    res = min(res, cell[3]);
                if(visited[x][y] > cell[3])
                {
                    for(int i = 0; i<4; i++)
                    {
                        q.push({x, y, i, cell[3]});   
                    }
                    visited[x][y]=cell[3];
                }
                
            }
        }
        if(res == INT_MAX)
            return -1;
        return res;
    }
};
