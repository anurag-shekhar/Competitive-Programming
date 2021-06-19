/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KInversePairsArray.cpp
 * Created on : Sat Jun 19 2021
 ****************************************************************
 */


#define MOD 1000000007
#define ll long long int
class Solution {
public:
    int kInversePairs(int n, int k) {
        
        vector<vector<ll> > dp(n+1, vector<ll>(k+1));
        
        for(int i = 0; i<n+1; i++)
        {
            for(int j = 0; j<k+1; j++)
            {
                if(j==0)
                    dp[i][j] = 1;
                else if(i==0)
                    dp[i][j] = 0;
                else 
                {
                    ll valToSubtract = j>=i ? dp[i-1][j-i] : 0;
                    ll valToAdd = dp[i-1][j];
                    dp[i][j] = dp[i][j-1] + valToAdd - valToSubtract + MOD;
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[n][k]%MOD;
    }
};
