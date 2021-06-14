class Solution {
public:
    vector<vector<bool> > isVisited;
    int r , c ;
    bool isValid(int i, int j)
    {
        if(0<=i && 0<=j && i<r && j<c )
            return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int idx)
    {
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
    
        if(board[i][j]!=word[idx])
             return false;
        
        if(idx==word.size()-1)
            return true;
                
        isVisited[i][j] = true;
        for(int k = 0; k<4; k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y) && !isVisited[x][y])
                if(dfs(board,x,y,word,idx+1))
                    return true;
        }
        isVisited[i][j]=false;
        return false;
    }    
    bool exist(vector<vector<char>>& board, string word) {
        
        r = board.size();
        c = board[0].size();
        isVisited = vector<vector<bool> >(r,vector<bool>(c,false));
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(dfs(board,i,j,word,0))
                    return true;
            }
        }
        return false;
        
    }
};
