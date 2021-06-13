/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 3Sum_handlingDuplicates.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left = i+1;
            int right = n-1;
            int target = -1*nums[i];
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum < target)
                    left++;
                else if(sum > target)
                    right--;
                else 
                {
                    res.push_back({nums[i], nums[left], nums[right]}) ;
                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
        
    }
};
