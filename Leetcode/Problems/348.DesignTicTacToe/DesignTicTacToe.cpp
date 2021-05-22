/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignTicTacToe.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */


class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int> > board;
    int size;
    TicTacToe(int n) {
        board = vector<vector<int> >(n,vector<int>(n,0));
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        board[row][col] = player;
        //vertical
        int winningFlag = true;
        for(int i = 0; i<size; i++) 
        {
            if(board[i][col] != board[row][col])
            {
                winningFlag = false;
                break;
            }    
        }
        if(winningFlag)
            return player;
        
        //Horizontal
        winningFlag = true;
        for(int i = 0; i<size; i++)
        {
            if(board[row][i] != board[row][col])
            {
                winningFlag = false;
                break;
            }
        }
        if(winningFlag)
            return player;
        
        //Left Diagonal
        winningFlag = true;
        if(row == col)
        {
            for(int i = 0; i<size; i++)
            {
                if(board[i][i] != board[row][col])
                {
                    winningFlag = false;
                    break;
                }
            }
                
        }
        else 
            winningFlag = false;
        if(winningFlag)
            return player;
        
        //right Diagonal
        winningFlag = true;
        if((row+col) == (size-1))
        {
            for(int i = 0; i<size; i++)
            {
                if(board[i][size-1-i] != board[row][col])
                {
                    winningFlag = false;
                    break;
                }
            }
        }
        else 
            winningFlag = false;
        if(winningFlag)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
