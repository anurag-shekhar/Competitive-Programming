bool solve(vector<int>& nums) {
    
    int n = nums.size();
    if(nums[0] >= nums[1])
        return false;

    for(int i = 1; i<n; i++)
    {
        if(nums[i]==nums[i-1])
            return false;
    }    
    return true;
}
