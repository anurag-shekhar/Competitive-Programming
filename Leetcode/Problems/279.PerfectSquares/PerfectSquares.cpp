/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PerfectSquares.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> squares;
        
        for(int i = 1; i*i<=n; i++)
        {
            squares.push_back(i*i);
        }
        
        int N = squares.size();
        vector<vector<int> > dp(N, vector<int> (n+1));
        
        for(int i = 0; i<N; i++)
        {
            for(int j = 0; j<n+1; j++)
            {
                if(j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = j;
                else 
                {
                    dp[i][j] = dp[i-1][j];
                    if(j>=squares[i])
                        dp[i][j] = min(dp[i][j], dp[i][j-squares[i]]+1);
                }
            }
        }
        return dp[N-1][n];
    }
};

/*

    0 1 2 3 4 5 6 7 8 9 10 11 12
 1  0 1 2 3 4 5 6 7 8 9 10 11 12
 4  0 1 2 3 1 2 3 4 2 3 4  5  3 
 9  0 1 2 3 1 2 3 4 2 1 2  3  4 
 */
