bool solve(vector<int>& nums, int k) {

    unordered_map<int,int> m;
    if(k==0)
        return true;

    for(int a : nums)
        m[a]++;

    int n = nums.size();

    for(pair<int,int> p : m)
    {
        if(p.second > n/k)
            return false;
    }    
    return true;
    
}
