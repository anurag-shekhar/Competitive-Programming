bool isValid(int i,int j, int r, int c)
{
    if(i<r && j<c && i>=0 && j>=0)
        return true;
    return false;    
}
void dfs(vector<vector<int>>& a, vector<vector<int>>& b, int i,int j, int r, int c,int &count)
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    
    a[i][j] = 0;
    b[i][j] = 0;

    for(int k = 0; k<4; k++)
    {
        int new_i = i+dx[k];
        int new_j = j+dy[k];
        if(isValid(new_i, new_j, r,c))
        {
            if(a[new_i][new_j] && b[new_i][new_j])
                dfs(a,b,new_i,new_j,r,c,count);
            else if( (a[new_i][new_j]+b[new_i][new_j])%2)
            {
                count = 0;    
            }    
        }
    }
    if(count == -1)
        count = 1;

}

int solve(vector<vector<int>>& a, vector<vector<int>>& b) {

    int r = a.size();
    if(r==0)
        return 0;
    int c = a[0].size();
    
    int res = 0;
    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            int count = -1;
            if(a[i][j] == 1 && b[i][j]==1)
                dfs(a,b,i,j,r,c,count);

            if(count != -1)
                res += count;   
        }
    }


    return res;
}
