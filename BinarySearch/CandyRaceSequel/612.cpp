/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 612.cpp
 * Created on : Tue May 11 2021
 ****************************************************************
 */

bool solve(vector<int>& nums) {
    
    int n = nums.size();
    vector<int> dp(n+1, 0);

    dp[n] = 0;
    for(int i = n-1; i>=0; i--)
    {
        dp[i] = nums[i] - dp[i+1];
        if(i+1 < n)
            dp[i] = max(dp[i],nums[i]+nums[i+1]-dp[i+2]);
        if(i+2 < n)
            dp[i] = max(dp[i], nums[i]+nums[i+1]+nums[i+2] - dp[i+3]);    
    }

    if(dp[0] > 0)
        return true;
    return false;    

}
