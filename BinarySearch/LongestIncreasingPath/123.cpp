bool isValid(int i, int j, int r, int c)
{
    if(0<=i && 0<=j && i<r && j<c)
        return true;
    return false;    
}

int traverse(vector<vector<int>>& matrix,vector<vector<int> > &dp, int i, int j, int r, int c)
{
    if(dp[i][j]!=-1)
        return dp[i][j];

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    int maxPath = 0;
    for(int k = 0; k<4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y,r,c) && matrix[x][y] > matrix[i][j] )
            maxPath = max(maxPath, traverse(matrix, dp, x, y, r, c));
    } 

    maxPath+=1;
    dp[i][j] = maxPath;
    return dp[i][j];   
}

int solve(vector<vector<int>>& matrix) {

    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int> > dp(r,vector<int> (c,-1));


    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            unordered_set<int> s;
            if(dp[i][j]==-1)
                dp[i][j] = traverse(matrix, dp, i, j, r,c);
            res = max(res, dp[i][j]);    
        }
    } 
    return res;
    
}
