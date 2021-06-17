/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 715.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

#define MOD 1000000007
int solve(string message) {
    int n =  message.size();
    vector<long> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1; i<=n; i++)
    {
        if(message[i-1] == '*')
        {
            dp[i] = dp[i-1]*9;
            dp[i] %= MOD;
        }
        else if(message[i-1] != '0')
            dp[i] = dp[i-1];
        
        if(message[i-2] == '1')
        {
            if(message[i-1] == '*')
            {
                dp[i] += (dp[i-2] * 9);
                dp[i] %= MOD;
            }
            else 
            {
                dp[i] += dp[i-2];
                dp[i] %= MOD;
            }
        }
            
        if(message[i-2] == '2')
        {
            if(message[i-1] == '*')
            {
                dp[i] += (dp[i-2] * 6);
                dp[i] %= MOD;
            }
            else if(message[i-1] <= '6')
            {
                dp[i] += dp[i-2];
                dp[i] %= MOD;
            }
        }

        if(message[i-2] == '*')
        {
            if(message[i-1] == '*')
            {
                dp[i] += (dp[i-2] * 15);
                dp[i] %= MOD;
            }
            else if(message[i-1] <='6')
            {
                dp[i] += (dp[i-2]*2);
                dp[i] %= MOD;
            }
            else 
            {
                dp[i] += (dp[i-2]);
                dp[i] %= MOD;
            }
        }
    }
    return dp[n]%MOD;

}
