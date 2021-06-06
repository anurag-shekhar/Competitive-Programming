/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumCostForTickets.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(366);
        dp[0] = 0;
        int dayIdx = 0; 
        for(int i = 1; i<366; i++)
        {
            if(dayIdx < n && i==days[dayIdx])
            {
                int day1 = costs[0];
                if(i-1 >= 0)
                    day1 += dp[i-1];
                
                int day7 = costs[1];
                if(i-7 >= 0 )
                    day7 += dp[i-7];
                
                int day30 = costs[2];
                if(i-30>=0)
                    day30 += dp[i-30];
                
                dp[i] = min(day1, min(day7, day30));
                dayIdx++;
            }
            else {
                dp[i] = dp[i-1];
                if(dayIdx==n)
                    return dp[i];
            }
        }
        return  dp[365];
    }
};
