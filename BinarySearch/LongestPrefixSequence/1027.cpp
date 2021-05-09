/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1027.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int dfs(vector<string>& words, vector<int> &dp, int i, int n)
{
    if(dp[i]!=-1)
        return dp[i];

    dp[i] = 1;
    int k = i+1;
    int longest = 0;
    while(k < n && ((words[k].size() - words[i].size()) <= 1) )
    {
        if(k < n && ((words[k].size() - words[i].size()) == 1))
            longest = max(longest, dfs(words,dp, k, n));
        k++;    
    }    
    dp[i] += longest;
    return dp[i];        
}

int solve(vector<string>& words) {

    int n = words.size();
    sort(words.begin(), words.end());

    vector<int> dp(n,-1);

    int res = 0;
    for(int i = 0; i<n; i++)
        res = max(res , dfs(words, dp, i, n));
    return res;

}
