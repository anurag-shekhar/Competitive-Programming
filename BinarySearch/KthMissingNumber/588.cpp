int solve(vector<int>& nums, int k) {
    
    int n = nums.size();
    for(int i = 0; i<n-1; i++)
    {   
        int delta = nums[i+1] - nums[i] -1;
        if(delta > k)
            return nums[i] + k+1;
        k -= delta;
    }
    return nums[n-1] + k+1;
    
    
}
