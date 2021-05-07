bool solve(vector<int>& nums) {
    unordered_map<int, int> subQ, count;

    for(int a : nums)
        count[a]++;
    for(int a : nums)
    {
        if(count[a]!=0)
        {
            auto itr = subQ.find(a-1);
            if(itr != subQ.end())
            {
                count[a]--;
                subQ[a-1]--;
                if(subQ[a-1]==0)
                    subQ.erase(a-1);
                subQ[a]++;    
            }
            else if(count[a+1]>0 && count[a+2] > 0) 
            {
                count[a]--;
                count[a+1]--;
                count[a+2]--;
                subQ[a+2]++;
            }
            else 
                return false;
        }
    }
    return true;
}
