/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : StoneGameVII.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
         
        int n = stones.size();
        vector<vector<int> > dp(n, vector<int> (n));
        
        vector<int> prefix(n+1);
        prefix[0] = 1;
        
        for(int i = 1; i<n+1; i++)
            prefix[i] = prefix[i-1] + stones[i-1];
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; i+j < n; j++)
            {
                int x = j;
                int y = i+j;
                int sum = prefix[y+1] - prefix[x];
                if(i==0)
                {
                    dp[x][y] = 0;
                }
                else if(i==1)
                {
                    
                    dp[x][y] = max(sum-stones[x], sum-stones[y]);
                }
                else 
                {
                     dp[x][y] = (sum-stones[x]) - dp[x+1][y];
                     dp[x][y] = max(dp[x][y], (sum-stones[y]) - dp[x][y-1]);
                }
            }
        }
        return dp[0][n-1] ;

    }
};
