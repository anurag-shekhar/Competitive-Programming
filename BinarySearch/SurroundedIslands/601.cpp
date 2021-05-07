bool isValid(int i, int j, int r, int c)
{
    if(0<=i && 0<=j && i<r && j<c)
        return true;
    return false;    
}
void fillZero( vector<vector<int>>& matrix, int i, int j,int r, int c)
{
    if(matrix[i][j]==0)
        return;

    matrix[i][j] =0;
    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1};

    for(int k = 0; k<4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k]; 
        if(isValid(x,y,r,c))
            fillZero(matrix, x, y, r,c);

    }

}

int solve(vector<vector<int>>& matrix) {
    
    int r = matrix.size();
    int c = matrix[0].size();

    for(int i = 0; i<r; i++)
    {
        fillZero(matrix, i, c-1,r,c);
        fillZero(matrix, i,0,r,c);
    }
    for(int j = 0; j<c; j++)
    {
        fillZero(matrix, 0, j,r,c);
        fillZero(matrix, r-1,j,r,c);
    }
    int count = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
             if(matrix[i][j]==1)
             {
                 fillZero(matrix, i, j, r, c);
                 count++;
             }   
        }   
    }
    return count;
    
}
