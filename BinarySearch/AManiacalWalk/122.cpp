/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 122.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

#define M 1000000007
int len;
vector<vector<long> > dp;
long travel(int steps, int pos)
{
    if(steps==0&&pos==0)
        return 1;
    if(steps ==0 || pos >= len  || pos < 0 || pos>steps)
        return 0;
    
    if(dp[steps][pos]==-1)
    {
        long stay = travel(steps-1, pos);
        long left = travel(steps-1, pos-1);
        long right = travel(steps-1, pos+1);
        dp[steps][pos] = (left%M + stay%M + right%M)%M;    
    }
    return dp[steps][pos];
    
}
int solve(int length, int n) {
    len = length;
    dp = vector<vector<long> >(n+1, vector<long> (n+1, -1));
    return travel(n, 0);
}



