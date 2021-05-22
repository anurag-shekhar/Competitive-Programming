/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignTicTacToe_optimised.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> row,col;
    int diagonal, anti_diagonal;
    int size;
    TicTacToe(int n) {
        
        row = vector<int> (n,0);
        col = vector<int> (n,0);
        diagonal = 0;
        anti_diagonal = 0;
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
    int move(int r, int c, int player) {
        int move = 1;
        if(player == 2)
            move = -1;
        
        row[r]+=move;
        if(row[r]==(size*move))
            return player;
        col[c]+=move;
        if(col[c]==(size*move))
            return player;
        
        if(r==c)
        {
            diagonal += move;
            if(diagonal==(size*move))
                return player;
        }
        
        if(r+c == size-1)
        {
            anti_diagonal += move;
            if(anti_diagonal==(size*move))
                return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
