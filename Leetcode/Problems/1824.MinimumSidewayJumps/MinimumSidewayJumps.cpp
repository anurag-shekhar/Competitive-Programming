/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumSidewayJumps.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<vector<int> > dp(3,vector<int>(n,INT_MAX-1));
        dp[1][0] = 0;
        int res = INT_MAX;
        dp[0][0] = 1;
        dp[2][0] = 1;
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<3; j++)
            {
                if((obstacles[i]-1) != j)
                {
                    if(j==0)
                    {
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j+1][i]+1);
                        if((obstacles[i]-1) != j+2)
                            dp[j][i] = min(dp[j][i], dp[j+2][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                            
                    }
                    else if(j==1)
                    {
                        if(obstacles[i]-1 != j-1)
                            dp[j][i] = min(dp[j][i], dp[j-1][i]+1);
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j+1][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                        
                    }
                    else 
                    {
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j-1][i]+1);
                        if(obstacles[i]-1 != j+2)
                            dp[j][i] = min(dp[j][i], dp[j-2][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                    }
                }
            }
            for(int j = 2 ; j>=0; j--)
            {
                if((obstacles[i]-1) != j)
                 {
                    if(j==0)
                    {
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j+1][i]+1);
                        if(obstacles[i]-1 != j+2)
                            dp[j][i] = min(dp[j][i], dp[j+2][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                            
                    }
                    else if(j==1)
                    {
                        if(obstacles[i]-1 != j-1)
                            dp[j][i] = min(dp[j][i], dp[j-1][i]+1);
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j+1][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                        
                    }
                    else 
                    {
                        if(obstacles[i]-1 != j+1)
                            dp[j][i] = min(dp[j][i], dp[j-1][i]+1);
                        if(obstacles[i]-1 != j+2)
                            dp[j][i] = min(dp[j][i], dp[j-2][i]+1);
                        if((obstacles[i-1]-1) != j)
                            dp[j][i] = min(dp[j][i], dp[j][i-1]+1);
                    }
                }
            }
        }
        
        // for(vector<int> V : dp)
        // {
        //     for(int v : V)
        //         cout<<v<<"               ";
        //     cout<<endl;
        // }
        // cout<<res<<endl;
        for(int i = 0; i<3; i++)
        {
            res = min(res, dp[i][n-1]);
        }
        return (res - (n-1));
        
    }
};
