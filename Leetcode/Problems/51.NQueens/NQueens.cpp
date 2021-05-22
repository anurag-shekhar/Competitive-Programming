/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NQueens.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    vector<bool> diagonal, anti_diagonal, col;
    
    bool isValid(int x,int y, int n)
    {
        if(col[y] || diagonal[y-x+n-1] || anti_diagonal[x+y])
            return false;
        return true;
    }
    void mark(int x, int y, int n)
    {
        col[y] = true;
        diagonal[y-x+n-1] = true;
        anti_diagonal[x+y] = true;
    }
    void unmark(int x, int y, int n)
    {
        col[y] = false;
        diagonal[y-x+n-1] = false;
        anti_diagonal[x+y] = false;
    }
    void backtrack(vector<vector<string > > &res,vector<string> &board, int x, int n)
    {
        if(x==n)
        {
            res.push_back(board);
            return;
        }

        for(int i = 0; i<n; i++)
        {
            if(isValid(x,i, n))
            {
                board[x][i] = 'Q';
                mark(x,i,n);
                backtrack(res, board, x+1, n);
                unmark(x,i,n);
                board[x][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        diagonal =vector<bool> (n + n-1,false);
        anti_diagonal =vector<bool> (n + n-1,false);
        col = vector<bool> (n,false);
        
        vector<vector<string > > res;
        
        string s = "";
        for(int i = 0; i<n; i++)
            s+=".";
        vector<string> board;
        for(int i = 0; i<n; i++)
            board.push_back(s);
        
        backtrack(res,board, 0, n);
        return res;
        
    }
};
