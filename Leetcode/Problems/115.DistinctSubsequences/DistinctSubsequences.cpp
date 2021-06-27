/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DistinctSubsequences.cpp
 * Created on : Mon Jun 28 2021
 ****************************************************************
 */

#define ll unsigned long long //important
class Solution {
public:
    
    int numDistinct(string s, string t) {
        
        int r = s.size();
        int c = t.size();
        
        vector<vector<ll> > dp = vector<vector<ll> > (r+1, vector<ll> (c+1,0));
        
        for(int i = 0; i<r+1; i++)
        {
            for(int j = 0; j<c+1; j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i == 0 || j>i)
                    dp[i][j] = 0;
                else 
                    dp[i][j] = (s[i-1] == t[j-1]) ? dp[i-1][j-1] + dp[i-1][j] : dp[i-1][j];
            }
        }
        return dp[r][c];
    }
};
