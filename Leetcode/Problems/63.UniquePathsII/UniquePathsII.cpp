/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UniquePathsII.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j] = 0;
                else if(i==0 && j==0)
                    obstacleGrid[i][j] = 1;
                else if(i==0)
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
                else if(j==0)
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                else 
                    obstacleGrid[i][j] += obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
            }
        }
        
        
        return obstacleGrid[r-1][c-1];
    }
};
