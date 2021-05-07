int solve(vector<int>& nums) {

    int n = nums.size();
    if(n==0||n==1)
        return n;
    vector<int> dp(n);

    dp[0] = 1;
    int res = 0;
    for(int i = 1; i<n; i++)
    {
        dp[i] = 1;
        for(int j =0; j<i; j++)
        {
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j]+1);

        }
        res = max(res , dp[i]);
    }
    return res;
}
