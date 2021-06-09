/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 592.cpp
 * Created on : Wed Jun 09 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int k) {

    int n = nums.size();
    vector<vector<int> > dp(n, vector<int> (k+1,0));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<k+1; j++)
        {
            if(j==0)
                dp[i][j] = 1;  
            else
            {
                dp[i][j] = 0;
                if(i-1>=0)
                    dp[i][j] = dp[i-1][j];
                if(j-nums[i] >=0)
                    dp[i][j] += dp[i][j-nums[i]];
            }
        }
    } 
    return dp[n-1][k];
}
/*
       1 2 3
    0  1 1 1 
    1  1 
    2
    3
    4
    5

    0 1 2 3 4 5
  1 1 1 1 1 1 1
  2 1 1 2 2 3 3
  3 1 1 2 3 4 5
 */
