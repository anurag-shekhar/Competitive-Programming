/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FloodFill.cpp
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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        
        queue<vector<int> > q;
        int oldColor = image[sr][sc];
        q.push({sr,sc});
        image[sr][sc] = -1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0,0,-1,1};
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            for(int k = 0; k<4; k++)
            {
                int x= cell[0] + dx[k];
                int y = cell[1] + dy[k];
                
                if(isValid(x,y,r,c) && image[x][y] == oldColor)
                {
                    q.push({x,y});
                    image[x][y] = -1;
                }
            }
        }
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(image[i][j] == -1)
                    image[i][j] = newColor;
            }
        }
        return image;
        
    }
};
