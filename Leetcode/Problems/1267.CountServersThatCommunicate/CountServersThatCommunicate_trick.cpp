/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountServersThatCommunicate_trick.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
           
        int r = grid.size();
        int c = grid[0].size();
        
        vector<int> row(r,0), col(c,0);

        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int count = 0;
        for(int j = 0; j<c; j++)
        {
            for(int i = 0; i<r; i++)
            {
                if(grid[i][j]==1 &&(col[j]+row[i] > 2))
                    count++;
            }
        }
        
        return count;
    }
};
