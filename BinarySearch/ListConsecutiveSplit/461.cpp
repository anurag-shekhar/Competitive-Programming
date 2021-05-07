bool solve(vector<int>& nums, int k) {
    
    if(k==0 || k==1)
        return true;
    int n = nums.size();
    if(n%k)
        return false; 
    sort(nums.begin(), nums.end());       
    unordered_map<int, priority_queue<int, vector<int>, greater<int> > > m;
    
    for(int i = 0; i<n; i++)
    {   
        auto itr = m.find(nums[i]-1);
        if(itr==m.end() || itr->second.top() == k )
            m[nums[i]].push(1);
        else 
        {
            if((itr->second.top()+1) != k)
                m[nums[i]].push(itr->second.top()+1);
            itr->second.pop(); 
            if(itr->second.size()==0)
                m.erase(nums[i]-1);
        }
    } 
    //1 2 3 3 4 5
    //1 1 1 2 2 2 
    if(m.size())
        return false;
    return true;
}
