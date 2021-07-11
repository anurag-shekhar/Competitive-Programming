/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NearestExitFromEntranceInMaze.cpp
 * Created on : Sun Jul 11 2021
 ****************************************************************
 */

class Solution {
public:
    int r,c;
    bool isValid(int x, int y)
    {
        if(x>=0 && x<r && y>=0 && y<c)
            return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        r = maze.size();
        c = maze[0].size();
        queue<vector<int> > q;
        q.push({entrance[0], entrance[1], 0});
        
        vector<vector<bool> > visited(r,vector<bool> (c,false));
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty())
        {
            vector<int> v = q.front();
            q.pop();
            
            if((v[0]==0 || v[0]==r-1 ||  v[1] == 0 || v[1] == c-1) && (v[0]!=entrance[0] || v[1]!=entrance[1]))
                return v[2];
            
            
            for(int k = 0; k<4; k++)
            {
                int x = v[0]+dx[k];
                int y = v[1] + dy[k];
                if(isValid(x,y) && maze[x][y]=='.' && !visited[x][y])
                {
                    q.push({x, y, v[2]+1});
                    visited[x][y] = true;
                } 
            }
        }
        return -1;
    }
};
