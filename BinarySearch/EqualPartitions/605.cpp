/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 605.cpp
 * Created on : Thu Jan 20 2022
 ****************************************************************
 */

bool solve(vector<int>& nums) {

    long sum = 0;

    for(int a : nums)
        sum += a;

    if(sum%2)
        return false;

    sum /=2;

    int n = nums.size();
    vector<vector<bool> > dp(n, vector<bool> (sum+1));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<sum+1; j++)
        {
            if(j == 0)
                dp[i][j] = true;
            else if(i == 0)
                dp[i][j] = (j == nums[i])? true : false;  
            else if(j < nums[i])
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]; 
        }
    }
    return dp[n-1][sum];    
}
