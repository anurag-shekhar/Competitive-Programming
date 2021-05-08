class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> m;
        for(int i = 0; i<nums.size(); i++)
        {
            int check  = target - nums[i];
            auto itr = m.find(check);
            if(itr!=m.end())
                return {itr->second,i};
            m[nums[i]] = i;
        }
        return {};
        
    }
};
