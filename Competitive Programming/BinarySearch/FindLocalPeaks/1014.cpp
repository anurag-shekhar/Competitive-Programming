vector<int> solve(vector<int>& nums) {

    int n = nums.size();
    vector<int> res;
    if(n==1)
        return res;
    for(int i = 0; i<n; i++)
    {
        if(i==0)
        {
            if(nums[i]>nums[i+1])
                res.push_back(i);
        }
        else if(i==n-1)
        {
           if(nums[i]>nums[i-1])
                res.push_back(i);
        }
        else 
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                res.push_back(i);
        }   
    }
    return res;
    
}
