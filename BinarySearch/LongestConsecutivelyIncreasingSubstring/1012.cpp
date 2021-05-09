/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1012.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(string s) {
    
    vector<int> dp(26,0);

    int n = s.size();
    int res = 0;
    for(int i = 0; i<n; i++)
    {
        int x = s[i]-'a';
        if(s[i]!='?')
        {
            if(s[i]=='a')
                dp[x]=1;
            else 
                dp[x] = dp[x-1]==0 ? 0 : max(dp[x], dp[x-1]+1);

            for(int j = 0; j<26; j++)
            {    if(x!=j)
                    dp[j] = 0;   
                res = max(res, dp[j]);     
            }        
        }
        else 
        {
            if(i>0)
            {   
                for(int j = 25; j>0; j--)
                {
                    if(dp[j-1])
                        dp[j] = max(dp[j], dp[j-1]+1); 
                    res = max(res, dp[j]);       
                }
            }
            dp[0] = 1;
            res = max(res,dp[0]);
        } 
    }
       
    return res;    

}
