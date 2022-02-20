/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindWinnerOnTicTacToeGame.cpp
 * Created on : Sun Feb 20 2022
 ****************************************************************
 */

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        int N = 3;
        vector<int> row(N, 0), col(N,0);
        
        int dia = 0, antiDia = 0;
        
        int noOfMoves = moves.size();
        
        int player = 1;
        for(int i = 0; i<noOfMoves; i++)
        {
            row[moves[i][0]] += player;
            col[moves[i][1]] += player;
            
            if(moves[i][0] == moves[i][1])
                dia += player;
            if(moves[i][0] + moves[i][1] == N-1)
                antiDia += player;
            
            if(abs(row[moves[i][0]]) == N || abs(col[moves[i][1]]) == N || abs(dia) == N || abs(antiDia)==N)
            {
                if(player == 1)
                    return "A";
                else 
                    return "B";
            }
            player *= -1;
        }
        
        if(N*N == noOfMoves)
            return "Draw";
        return "Pending";
      
    }
};