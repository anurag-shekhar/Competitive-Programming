/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestCommonSubsequence.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int r = text1.size();
        int c = text2.size();
        
        vector<vector<int> > dp(r, vector<int> (c)); 
        for(int i = 0; i<r; i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(i==0 && j ==0)
                    dp[i][j] = text1[i]==text2[j] ? 1 : 0;
                else if(i==0)
                    dp[i][j] = text1[i]==text2[j] ? 1 : dp[i][j-1];
                else if(j==0)
                    dp[i][j] = text1[i]==text2[j] ? 1 : dp[i-1][j];
                else 
                    dp[i][j] = text1[i]==text2[j] ? 1+dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
                
            }
        }
        return dp[r-1][c-1];
    }
};

/*

            f(abcde, ace)
        f(abcd, ace)   f(abcde, ac)   
abcde

ace


        
        a b c d e 
      a 1 1 1 1 1
      c 1 1 2 2 2
      e 1 1 2 2 3
*/
