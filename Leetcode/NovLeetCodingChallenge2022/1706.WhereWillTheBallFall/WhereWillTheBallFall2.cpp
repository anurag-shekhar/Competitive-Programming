/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : WhereWillTheBallFall2.cpp
 * Created on : Tue Nov 01 2022 
 ***************************************************************
 */

class Solution {
public:
    
    int ballDrop(vector<vector<int>>& grid, int col ,int r, int c) {
        
        for(int row = 0; row<r; row++) {
            
            if(grid[row][col] == 1) {
                if(col == c-1 || grid[row][col+1] == -1)
                    return -1;
                col += 1;
            } else {
                if(col == 0 || grid[row][col-1] == 1)
                    return -1;
                col += -1;
            }
        }
        return col;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        vector<int> result;
        
        for(int i = 0; i<c; i++) {
            result.push_back(ballDrop(grid, i, r, c));
        }
        return result;
    }
};