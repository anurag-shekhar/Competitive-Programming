class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        if(amount == 0)
            return 0;
        int r = nums.size(); 
        int c = amount+1;
        vector<vector<int> > dp(r,vector<int>(c,0));
        
        
        for(int i = 0; i<r;i++)
        {
            for(int j = 0; j<c; j++)
            {
                if(i==0)
                {
                    if(nums[i]<=j && j%nums[i]==0)
                        dp[i][j] = dp[i][j-nums[i]] + 1;
                    else if(j == 0)
                        dp[i][j] = 0;
                    else 
                        dp[i][j] = 10000;
                }
                else if(nums[i]<=j)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-nums[i]] + 1);
                }
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        
//         for(vector<int> v : dp)
//         {
//             for(int a: v)
//                 cout<<a<<" ";
//             cout<<endl;
//         }
        if(dp[r-1][c-1] == 10000)
            return -1;
        return dp[r-1][c-1];
        
    }
};
