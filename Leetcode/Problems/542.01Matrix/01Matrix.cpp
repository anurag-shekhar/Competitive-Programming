/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 01Matrix.cpp
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        
        queue<vector<int> > q;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(mat[i][j] == 0)
                    q.push({i,j,0});
                else 
                    mat[i][j] = INT_MAX;
            }
        }
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0,-1, 1};
        while(!q.empty())
        {
            vector<int> cell = q.front();
            q.pop();
            
            for(int k = 0; k<4; k++)
            {
                int x = cell[0] + dx[k];
                int y = cell[1] + dy[k];
                if(isValid(x,y,r,c) && mat[x][y] > cell[2]+1)
                {
                    mat[x][y] = cell[2]+1;
                    q.push({x,y,mat[x][y]});
                }
            }
        }
        return mat;
        
    }
};
