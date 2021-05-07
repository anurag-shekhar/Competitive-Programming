int isValid(int i, int j, int r , int c)
{
    if(0<=i && 0<=j && j<c && i<r)
        return true;
    return false;    
}
int dfs(vector<vector<int>>& matrix, int i, int j, int r, int c)
{
    matrix[i][j] = 0;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    int count  = 1;
    for(int k = 0; k<4; k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if(isValid(x, y, r, c) && matrix[x][y]==1)
            count += dfs(matrix, x,y,r,c);
    }
    return count;

}

int solve(vector<vector<int>>& matrix) {

    int r = matrix.size();
    int c = matrix[0].size();
    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(matrix[i][j] == 1)
                res = max(res,dfs(matrix, i, j, r, c));
        }
    }
    return res;
    
}
