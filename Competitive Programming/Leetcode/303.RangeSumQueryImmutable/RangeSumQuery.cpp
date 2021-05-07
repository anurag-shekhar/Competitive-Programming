class NumArray {
public:
    vector<int> sums;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(i==0)
                sums.push_back(nums[i]);
            else
                sums.push_back(nums[i]+sums[i-1]);
        }
        
    }
    
    int sumRange(int left, int right) {
        
        if(right<left)
            return 0;
        if(left==0)
            return sums[right];
        return (sumRange(0,right) - sumRange(0,left-1));
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
