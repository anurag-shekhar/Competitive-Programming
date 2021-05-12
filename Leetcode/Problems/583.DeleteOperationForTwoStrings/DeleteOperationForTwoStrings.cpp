/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DeleteOperationForTwoStrings.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int r = word1.size();
        int c = word2.size();
        
        vector<vector<int> > dp(r+1, vector<int>(c+1));
        
        for(int i = 0; i<=r; i++)
        {
            for(int j = 0; j<=c; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = dp[i][j-1]+1;
                else if(j==0)
                    dp[i][j] = dp[i-1][j]+1;
                else 
                    dp[i][j] = word1[i-1]!=word2[j-1] ? min(dp[i-1][j],dp[i][j-1])+1 : dp[i-1][j-1]; 
            }
        }
        return dp[r][c];
        
    }
};
