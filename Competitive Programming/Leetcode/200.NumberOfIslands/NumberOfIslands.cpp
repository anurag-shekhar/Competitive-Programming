class Solution {
public:
    bool isValid(int i, int j, int r,int c)
    {
        if(0<=i && 0<=j && j<c && i<r)
            return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid, int i ,int j,int r,int c)
    {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0 ,0 ,-1,1};
        grid[i][j] = '0';
        for(int k = 0; k<4; k++)
        {
            int x = i+dx[k];
            int y = j + dy[k];
            if(isValid(x,y,r,c) && grid[x][y] == '1')
                dfs(grid,x,y,r,c);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int count = 0; 
        for(int i = 0; i<r; i++)
        {
            for(int j = 0;j < c;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j,r,c);
                }
            }
        }
        return count;
            
        
    }
};
