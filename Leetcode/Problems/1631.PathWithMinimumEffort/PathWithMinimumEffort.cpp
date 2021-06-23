/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PathWithMinimumEffort.cpp
 * Created on : Wed Jun 23 2021
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

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > minHeap;
        
        vector<vector<int> > effort(r, vector<int> (c,INT_MAX));
        effort[0][0] = 0;
        minHeap.push({0,0,0});
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        while(!minHeap.empty())
        {
            vector<int> v = minHeap.top();
            minHeap.pop();
            
            if(v[1]==r-1 && v[2] == c-1)
                return v[0];
            
            for(int k = 0; k<4; k++)
            {
                int x = v[1] + dx[k];
                int y = v[2] + dy[k];
                
                if(isValid(x,y,r,c))
                {
                    int val = max(v[0], abs(heights[x][y] - heights[v[1]][v[2]]));
                    if(val < effort[x][y])
                    {
                        effort[x][y] = val;
                        minHeap.push({val, x, y});
                    }
                }
            }
        }
        return -1;
    }
};
