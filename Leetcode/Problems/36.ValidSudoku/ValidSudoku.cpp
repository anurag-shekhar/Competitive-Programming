/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidSudoku.cpp
 * Created on : Tue Jan 25 2022
 ****************************************************************
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> row(9, 0);
        vector<int> col(9, 0);
        vector<int> box(9, 0);
        
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j]-'0';
                if((1<<val) & row[i])
                    return false;
                else 
                    row[i] += (1<<val);
                
                if((col[j]>>val) & 1)
                    return false;
                else 
                    col[j] += 1<<val;
                
                int idx = (i/3)*3 + j/3;
                if((box[idx] >> val) & 1)
                    return false;
                else 
                    box[idx] += 1<<val;
            }
        }
        return true;
    }
};
