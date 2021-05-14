/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 408.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

bool isValid(int i, int j, int r, int c)
{
    if(i>=0 && j>=0 && i<r && j<c)
        return true;
    return false;    
}
int dfs(vector<vector<int>>& matrix, int i, int j, int r, int c, int &perimeter)
{
    if(matrix[i][j] == 0)
        return 0;
    else if(matrix[i][j] == 2)
        return 1;    
    int neighbours = 4;

    matrix[i][j] = 2;
    int dx[] = {-1,1, 0, 0};
    int dy[] = {0,0,-1,1};

    for(int k = 0; k<4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y,r,c))
        {
            neighbours -= dfs(matrix,x,y,r,c,perimeter);
        }
    }
    perimeter += neighbours;
    return 1;
}
int solve(vector<vector<int>>& matrix) {
    int r = matrix.size(); 
    int c = matrix[0].size();
    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(matrix[i][j])
            {
                dfs(matrix, i, j, r,c, res);
                return res;
            }
        }
    }
    return res;
}
