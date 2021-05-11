/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : StoneGame.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*
            
            f(i,j) = max(piles[i] + min(f(i+2,j),f(i+1,j-1)) , 
                         piles[j] + min(f(i+1,j-1) , f(i,j-2)))
        */
        
        int n = piles.size();
        vector<vector<int> > dp(n, vector<int>(n));
        for(int i = 1; i<n; i+=2)
        {
            for(int j = 0; i+j<n ; j++)
            {
                int x = j;
                int y = i+j;
                if(i==1)
                    dp[x][y] = max(piles[x],piles[y]);
                else
                    dp[x][y] = max(piles[x] + min(dp[x+2][y],dp[x+1][y-1]),
                                   piles[y] + min(dp[x+1][y-1] , dp[x][y-2]));
            }
        }
        int sum = accumulate(piles.begin(), piles.end(), 0);
        sum /=2;
        return sum < dp[0][n-1];
        
    }
};
