/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 4KeysKeyboard.cpp
 * Created on : Mon Jun 07 2021
 ****************************************************************
 */

class Solution {
public:
    int maxA(int n) {
      
        vector<int> dp(n+1);
        for(int i = 0; i<=n; i++)
        {
            dp[i] = i;
            if(i>=3)
            {
                for(int j = i;j>=3; j--)
                    dp[i] = max(dp[i], dp[j-3] + dp[j-3]*(i-j+1));
            }
        }
        
        return dp[n];
    }
};

/*
    0 1 2 3 4 5 6 7
    0 1 2 3 4 5 6 
  A 0 1 2 3 4 5 6 7
 CA 0 0 1 2 3 4 5 6
 CC 0 0 0 1 2 3 4 5
 CV 0 0 0 0 1 2 3 4 
*/


