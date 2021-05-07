class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();
        int totalXOR = nums[0];
        
        for(int i = 1; i<n; i++)
            totalXOR ^= nums[i];
        
        vector<int> res;
        for(int i = n-1; i>=0; i--)
        {
            int k =0;
            int convert = totalXOR;
            stack<int> s;
            while(convert)
            {
                int binary = convert%2;
                s.push((binary+1)%2);
                convert/=2;
            }
            while(s.size()<maximumBit)
                s.push(1);
            
            while(!s.empty())
            {
                k = k*2 + s.top();
                s.pop();
            }
            res.push_back(k);
            totalXOR ^= nums[i];
        }
        return res;
        
    }
};
