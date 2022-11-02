/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : WhereWillTheBallFall.cpp
 * Created on : Wed May 26 2021
 ****************************************************************
 */

class Solution {
public:
    
    int drop(vector<vector<int>>& grid, int pos)
    {
        int r = grid.size();
        int c = grid[0].size();
        
        int x = 0, y = pos;
        while(x<r)
        {
            
            if(y<0 || y >= c)
                return -1;
            if(grid[x][y] == 1)
            {
                if(y+1 >= c || grid[x][y+1] == -1)
                    return -1;
                y++;
            }
            else
            {
                if(y-1<0 || grid[x][y-1] == 1)
                    return -1;
                y--;
            }        
            x++;
        }
        return y;
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        vector<int> res(c);
        for(int i = 0; i<c; i++)
        {
            res[i] = drop(grid, i);
        }
        return res;
    }
};
/*
1 -1
^    
1 -1
   ^    
   
1 wall
^

wall -1
      ^
      
*/      
