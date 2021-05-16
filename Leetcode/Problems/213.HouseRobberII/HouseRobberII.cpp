class Solution {
public:
    
    int PreviousHouseRobber(vector<int> &nums, int start, int end)
    {
        if((end - start) < 0)
            return 0;
        
        int first = 0,second = 0,third = 0;
        
        for(int i = start; i<=end; i++)
        {
            if(i == start)
                third = nums[i];
            else 
                third = max(nums[i]+first,second);
            
            first = second;
            second = third; 
        }
        return third;
        
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0)
            return 0;
        
        return max(nums[0] + PreviousHouseRobber(nums,2,n-2), PreviousHouseRobber(nums,1,n-1));
        
    }
};
