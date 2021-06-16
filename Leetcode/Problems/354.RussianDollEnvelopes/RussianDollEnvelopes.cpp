/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RussianDollEnvelopes.cpp
 * Created on : Wed Jun 16 2021
 ****************************************************************
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        
        sort(envelopes.begin(), envelopes.end());
        
        int n = envelopes.size();
        
        vector<int> dp(n+1, 1);
        int res = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = i-1; j>=0; j--)
            {
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(dp[i], res);
        }
        
        return res;
        
    }
};
