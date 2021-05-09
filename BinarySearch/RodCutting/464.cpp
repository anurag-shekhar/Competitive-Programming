/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 464.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& prices, int n) {
    
    int r = prices.size();
    int c = n+1;
    vector<vector<int> > dp(r,vector<int>(c));


    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c; j++)
        {
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = (i+1 <= j) ? dp[i][j-i-1]+prices[i] : 0;
            else     
            {
                dp[i][j] = dp[i-1][j];
                if(i+1 <= j)
                    dp[i][j] = max(dp[i][j], dp[i][j-i-1] + prices[i]);
            }    
        }
    }
    return dp[r-1][c-1];
}
