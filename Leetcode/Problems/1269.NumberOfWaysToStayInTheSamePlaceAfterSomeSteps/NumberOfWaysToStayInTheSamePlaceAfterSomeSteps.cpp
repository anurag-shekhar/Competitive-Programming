/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfWaysToStayInTheSamePlaceAfterSomeSteps.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */

#define M 1000000007
class Solution {
public:
    
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
    int numWays(int steps, int arrLen) {
        
        len = arrLen;
        dp = vector<vector<long> >(steps+1, vector<long> (steps+1, -1));
        
        return travel(steps, 0);
    }
};
