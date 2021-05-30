/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : GetBiggestThreeRhombusSumsInGrid.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int> > diagonal(r, vector<int> (c, 0));
        vector<vector<int> > anti_diagonal(r, vector<int> (c, 0));
        
        set<int> res;
        for(int i = 0; i<r; i++)
        {
            for(int j = 0;j<c; j++)
            {
                res.insert(grid[i][j]);
                int x = r-1-i;
                int y = c-1-j;
                anti_diagonal[x][y] = grid[x][y];
                if(x+1 < r && y-1 >=0)
                    anti_diagonal[x][y] += anti_diagonal[x+1][y-1];
                
                diagonal[i][j] = grid[i][j];
                if(i-1 >=0  && j-1 >=0)
                    diagonal[i][j] += diagonal[i-1][j-1];
            }
        }
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0;j<c; j++)
            {
                
                for(int x = i-1, y = j+1; x>=0 && y<c; x--, y++)
                {
                    int side = y - j;
                    
                    pair<int,int> p1 = make_pair(i+side, j+side);
                    pair<int,int> p2 = make_pair(x+side, y+side);
                    
                    if(p1.first <r && p1.second<c && p2.first <r && p2.second<c)
                    {
                        int sum = anti_diagonal[x][y] - anti_diagonal[i][j];
                        sum += anti_diagonal[p2.first][p2.second] - anti_diagonal[p1.first][p1.second];             
                        sum += diagonal[p1.first][p1.second] - diagonal[i][j] + grid[i][j];
                        sum += diagonal[p2.first][p2.second] - diagonal[x][y] - grid[p2.first][p2.second];
                        res.insert(sum);
                    } 
                    
                }
            }
        }
    
        vector<int> finalRes;
        for(auto itr = res.rbegin(); itr!=res.rend(); itr++)
        {
            finalRes.push_back(*itr);
            if(finalRes.size()==3)
                return finalRes;
        }
        return finalRes;
    }
};




/*

0 1 2 3 4 5 6
            
            prefix[6] += prefix[5]
diagoanl
00
    11      
        22
        prefix[22] += prefix[11]
        
        
        anti
        
        prefix[02] += prefix[11]
                02
            11
        20
        
        


9 *
        02
                
20          24

    42

_ _ * _ _ _ _ _ _ 
_ _ _ _ * _ _ _ _ 
* _ _ _ _ _ _ _ _
_ _ * _ _ _ _ _ _
_ _ _ _ _ _ _ _ _

*/
