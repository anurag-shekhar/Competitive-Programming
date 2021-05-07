int solve(vector<int>& nums, int k) {

    int n = nums.size();
    for(int i = 1; i<n; i++)
        nums[i] += nums[i-1];

    int sum = INT_MIN;
    int left = 0, right = n-k-1;

    if(n==k)
        return nums[n-1];
    while(right<n)
    {
        if(left>0)
            sum = max(sum , nums[left-1]+nums[n-1] - nums[right]);   
        else 
            sum = max(sum ,nums[n-1] - nums[right]);
        
        left++;
        right++;       
    }
    return sum;

    
}
