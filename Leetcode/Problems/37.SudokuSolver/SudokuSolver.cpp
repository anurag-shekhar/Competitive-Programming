class Solution {
public:
    
    bool isValid(vector<vector<char> > &board, int i, int j, char ch)
    {
        unordered_set<char> s;
        for(int k = 0; k<9; k++)
            if(board[k][j]!='.')
                s.insert(board[k][j]);
        
        for(int k = 0; k<9; k++)
            if(board[i][k]!='.')
                s.insert(board[i][k]);
        
        int x = (i/3)*3;
        int y = (j/3)*3;
        for(int a = x; a<x+3; a++)
        {
            for(int b = y; b<y+3; b++)
            {
                if(board[a][b]!='.')
                    s.insert(board[a][b]);
            }
        }
        
        
        if(s.find(ch) == s.end())
            return true;
        return false;
        
    }
    bool solve(vector<vector<char> > &board, int i, int j)
    {
        
        if(i==8 && j == 9)
            return true; 
        if(j==9)
        {
            i++;
            j = 0;
        }
        
        if(board[i][j]!='.')
        {
            return solve(board,i, j+1);
        }
        
        for(char ch = '1' ; ch<='9'; ch++)
        {
            if(isValid(board, i,j,ch))
            {
                board[i][j] = ch;
                if(solve(board, i, j+1))
                    return true;
                board[i][j] = '.';
            }
        } 
        return false;     
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0,0);
        return;
    }
};
