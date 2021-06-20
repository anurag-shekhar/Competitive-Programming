/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SwimInRisingWater.cpp
 * Created on : Sun Jun 20 2021
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
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool> > visited(r, vector<bool> (c, false));
        priority_queue<vector<int> , vector<vector<int> >, greater<vector<int> > > minHeap;
        
        
        int res = 0;
        minHeap.push({grid[0][0], 0, 0});
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        visited[0][0] = true;
        while(!minHeap.empty())
        {
            vector<int> pt = minHeap.top();
            minHeap.pop();
            
            res = max(res, pt[0]);
            if(pt[1] == r-1 && pt[2] == c-1)
                return res;
            
            for(int k = 0; k<4; k++)
            {
                int x = pt[1]+dx[k];
                int y = pt[2]+dy[k];
                if(isValid(x, y, r, c) && !visited[x][y])
                {
                    minHeap.push({grid[x][y], x, y});
                    visited[x][y] = true;
                }
            }   
        } 
        return -1;
            
    }
};
