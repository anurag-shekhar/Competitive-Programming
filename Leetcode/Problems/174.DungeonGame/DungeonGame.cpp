/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DungeonGame.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int r = dungeon.size();
        int c = dungeon[0].size();
        for(int i = r-1; i>=0; i--)
        {
            for(int j = c-1; j>=0; j--)
            {
                if(i==r-1 && j==c-1)
                    dungeon[i][j] = min(0, dungeon[i][j]);
                else if(i==r-1)
                    dungeon[i][j] = min(0, dungeon[i][j] + dungeon[i][j+1]);
                else if(j==c-1)
                    dungeon[i][j] = min(0, dungeon[i][j] + dungeon[i+1][j]);
                else 
                    dungeon[i][j] = min(0, dungeon[i][j] + max(dungeon[i+1][j],dungeon[i][j+1]));
            }   
        }
        return abs(dungeon[0][0]) + 1;
    }
};
