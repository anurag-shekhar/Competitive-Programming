/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : EditDistance.cpp
 * Created on : Mon Oct 04 2021
 ****************************************************************
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int w1 = word1.size();
        int w2 = word2.size();
        
        vector<vector<int> > dp(w1+1, vector<int> (w2+1));
        
        for(int i = 0; i<=w1; i++)
        {
            for(int j = 0; j<=w2; j++)
            {
                if(i==0)
                    dp[i][j] = j;
                else if(j==0)
                    dp[i][j] = i;
                else 
                {
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    else 
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) +1 ;
                }
                    
            }
        }
        return dp[w1][w2];
    }
};
