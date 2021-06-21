/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PascalsTriangle.cpp
 * Created on : Mon Jun 21 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> >  dp(numRows);
        dp[0].push_back({1});
        
        for(int i = 1; i<numRows; i++)
        {
            for(int j = 0; j<=i; j++)
            {
                if(j==0)
                    dp[i].push_back(dp[i-1][j]);
                else if(i==j)
                    dp[i].push_back(dp[i-1][j-1]);
                else 
                    dp[i].push_back(dp[i-1][j] + dp[i-1][j-1]);
            }
        }
        return dp;
    }
};
/*
1
1 1
1 2 1
*/
