class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n==0)
            return 0;
        if(n>=1)
            nums[0] = max(0, nums[0]);
        if(n>=2)
            nums[1] = max(0, max(nums[1], nums[0]));    
        for(int i = 2; i<n; i++)
        {
            nums[i] = max(max(nums[i] + nums[i-2], nums[i-1]),0);
        }

        return nums[n-1];
    }
};
