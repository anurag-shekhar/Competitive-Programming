/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 654.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

bool solve(string s, int k) {

    int n = s.size();
    string original = s;
    reverse(s.begin(), s.end());

    vector<vector<int> > dp(n, vector<int> (n, 0));
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i==0 && j==0)
                dp[i][j] = original[i] == s[j] ? 1 : 0;
            if(i==0)
            {
                dp[i][j] = original[i] == s[j] ? 1 : dp[i][j-1];
            }
            else if(j==0)
                dp[i][j] = original[i] == s[j] ? 1 : dp[i-1][j];
            else 
                dp[i][j] = original[i] == s[j] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]); 
        }
    }

    if(n-dp[n-1][n-1] <= k)
        return true;
    return false;
   
}
