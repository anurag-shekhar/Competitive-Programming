class Solution {
public:
    class cell
    {
        public:
        int x;
        int y;
        int height;
        cell(int a, int b, int c): x(a), y(b), height(c){}
    };
    
    bool isValid(int x, int y, int r, int c)
    {
        if(x>=0 && y>=0 && x<r && y<c)
            return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int row = isWater.size();
        int col = isWater[0].size();
        
        vector<vector<int> > heightMatrix(row,vector<int>(col,INT_MAX));
        
        queue<cell*> q;
        
        //Finding all water bodies
        for(int i = 0; i<row; i++)
            for(int j = 0; j<col; j++)
                if(isWater[i][j]==1)
                    q.push(new cell(i,j,0));
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        
        //adjusting heights for lands
        while(!q.empty())
        {
            cell *c = q.front();
            q.pop();
            
            if(c->height < heightMatrix[c->x][c->y])
            {
                heightMatrix[c->x][c->y] = c->height;
                
                for(int i = 0; i<4; i++)
                {
                    if(isValid(c->x+dx[i],c->y+dy[i],row,col))
                        q.push(new cell(c->x+dx[i], c->y+dy[i], c->height+1));
                }
            }
        }
        return heightMatrix;
        
        
    }
};
