int atmostK(vector<int>& nums, int k)
{
    int left = 0, right = 0;
    unordered_map<int,int> m;
    int n = nums.size();
    int res = 0;
    while(right<n)
    {
        m[nums[right]]++;

        while(left < n && m.size() > k)
        {
            m[nums[left]]--;
            if(m[nums[left]]==0)
                m.erase(nums[left]);
            left++;    
        }
        res += (right - left + 1);
        right++;
    }
    return res;
}

int solve(vector<int>& nums, int k) {
    
    return (atmostK(nums,k) - atmostK(nums,k-1));
}
