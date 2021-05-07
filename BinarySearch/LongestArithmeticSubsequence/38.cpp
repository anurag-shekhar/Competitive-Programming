int solve(vector<int>& nums) {
    
    int n = nums.size();
    if(n==0 || n==1)
        return n;    
   vector<unordered_map<int,int> > dp(n);
    int res = 2;

    for(int i = 0; i<n; i++)
    {
        for(int j = i-1; j>=0; j--)
        {
            int diff = nums[i] - nums[j];
            auto itr = dp[j].find(diff);
            if(itr == dp[j].end())
                dp[i][diff] = max(2,dp[i][diff]);
            else 
                dp[i][diff] = max(dp[i][diff], dp[j][diff]+1);    

            res = max(res,dp[i][diff]);  
        }
    }
    return res;    
    
}


/* 
explaination
https://www.youtube.com/watch?v=-NIlLdVKBFs

*/
