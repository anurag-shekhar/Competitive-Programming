/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BurstBalloons.cpp
 * Created on : Thu Jun 10 2021
 ****************************************************************
 */


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size(); 
        vector<vector<int> > dp(n,vector<int> (n, 0));
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; i+j<n; j++)
            {
                int x = j;
                int y = i+j;
                for(int k = x; k<=y; k++)
                {
                    int leftSubProblem = k==x? 0 : dp[x][k-1];
                    int rightSubProblem = k==y ? 0 : dp[k+1][y];
                   
                    int leftVal = x==0 ? 1 : nums[x-1];
                    int rightVal = y==n-1 ? 1 : nums[y+1];
                    int val =  leftVal * nums[k] * rightVal;
                    
                    dp[x][y] = max(dp[x][y], leftSubProblem + val + rightSubProblem);
                    
                }
            }
        }
        return dp[0][n-1];
    }
};
/*
        
           3   1   5   8
        3  3   30        
        1      15  135    
        5          40   0 
        8              40

3 1 5 8
                    3 1 5 8 
            1 5 8                 3 5 8 
     5 8      1 8            5 8
  8 .    5   8.   5 
*/
