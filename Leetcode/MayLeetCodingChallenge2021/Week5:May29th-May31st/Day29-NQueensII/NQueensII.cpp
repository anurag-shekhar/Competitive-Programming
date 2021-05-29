/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NQueensII.cpp
 * Created on : Sat May 29 2021
 ****************************************************************
 */

class Solution {
public:
    
    vector<vector<char> > board;
    vector<bool> col, dia, anti_dia;
    int count;
    
    bool isValid(int r, int c, int n)
    {
        if(col[c] || dia[n-1+c-r] || anti_dia[r+c])
            return false;
        return true;
    }
    void mark(int r, int c, int n)
    {
        dia[n-1+c-r] = true;
        anti_dia[r+c] = true;
        col[c] = true;
    }
    void unmark(int r, int c, int n)
    {
        dia[n-1+c-r] = false;
        anti_dia[r+c] = false;
        col[c] = false;
    }
    void backtrack(int r, int n)
    {
        if(r==n)
        {
            count++;
            return;
        }
        
        for(int i = 0; i<n; i++)
        {
            if(isValid(r,i, n))
            {
                board[r][i] = 'Q';
                mark(r,i,n);
                backtrack(r+1, n);
                unmark(r,i,n);
                board[r][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        
        count = 0;
        board = vector<vector<char> > (n, vector<char> (n, '.'));
        dia = vector<bool> (n+n-1, false);
        anti_dia = vector<bool> (n+n-1, false);
        col = vector<bool> (n, false);
        
        backtrack(0,n);
        return count;
    }
};
