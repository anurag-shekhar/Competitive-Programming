/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 2KeysKeyboard.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int minSteps(int n) {
        
        vector<int> dp(n+1);
        
        dp[1] = 0;
        for(int i = 2; i<=n; i++)
        {
            dp[i] = INT_MAX;
            for(int j = 1; j<=(i/2); j++)
            {
                if(i%j==0)
                {
                    dp[i] = min(dp[i], dp[j] + i/j);
                }
            }
        }
        return dp[n];
    }
};

/*
 01234
 0AAAA
 0023 
*/
