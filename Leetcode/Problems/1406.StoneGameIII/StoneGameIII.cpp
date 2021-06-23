/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : StoneGameIII.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        
        int n = stoneValue.size();
        vector<int> dp(n+1);
        dp[n] = 0;
        
        for(int i = n-1; i>=0; i--)
        {
            dp[i] = stoneValue[i] - dp[i+1];
            if(i+2 < n+1)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] - dp[i+2]);
            if(i+3 < n+1)
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3]);
        }
        if(dp[0] == 0)
            return "Tie";
        else if(dp[0] > 0)
            return "Alice";
        return "Bob";
    }
};
/*
[1,2, 3, -1,-2,-3,7]
  0 1 8  -3  2  4 7 0



-3 , -7, -13
*/
