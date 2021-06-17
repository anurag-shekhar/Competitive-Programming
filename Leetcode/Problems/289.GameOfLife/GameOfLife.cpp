/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GameOfLife.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int r = board.size();
        int c = board[0].size();
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                int live = 0;
                for(int x = i-1; x<=i+1; x++)
                {
                    for(int y = j-1; y<=j+1; y++)
                    {
                        if(x>=0 && x<r && y>=0 && y<c && (x!=i || y!=j))
                        {
                            
                            if(board[x][y] == 1 || board[x][y]== -1)
                                live++;
                        }
                    }
                }
                if(board[i][j] == 1)
                {
                    if(live < 2 || live > 3)
                        board[i][j] = -1;
                }
                else 
                {
                    if(live ==3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
    }
};
/*

 A->D (-1)
 A->A (1)
 D->D (0)
 D->A (2)
 0 1 1    1
 0 1 2
 1 3 5
 1 3 5 
*/
