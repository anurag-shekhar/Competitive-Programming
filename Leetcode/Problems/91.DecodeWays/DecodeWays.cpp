/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DecodeWays.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = s[0]!='0' ? 1 : 0;
        
        for(int i = 2; i<=n; i++)
        {
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(s[i-2] == '1')
                dp[i] += dp[i-2];
            if(s[i-2] == '2' && s[i-1]<='6')
                dp[i] += dp[i-2];   

        }
        return dp[n];
    }
};
