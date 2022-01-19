/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 623.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

bool isValid(int x ,int y, int r, int c)
{
    if(x>=0 && y>=0 && x<r && y<c)
        return true;
    return false;

}
vector<vector<int>> solve(vector<vector<int>>& matrix) {

    queue<vector<int> > q;

    int r = matrix.size();
    int c = matrix[0].size();
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(matrix[i][j] == 0)
                q.push({i,j,0});
            else 
                matrix[i][j] = INT_MAX;
        }
    }

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,1,-1};
    while(!q.empty())
    {
        vector<int> coordinates = q.front();
        q.pop();
        for(int k = 0; k<4; k++)
        {
            int x = coordinates[0] + dx[k];
            int y = coordinates[1] + dy[k];
            if(isValid(x,y, r,c) && matrix[x][y] > coordinates[2]+1)
            {
                matrix[x][y] = coordinates[2] + 1;
                q.push({x,y,matrix[x][y]});
            }
        }
    }
    return matrix;
    
}
