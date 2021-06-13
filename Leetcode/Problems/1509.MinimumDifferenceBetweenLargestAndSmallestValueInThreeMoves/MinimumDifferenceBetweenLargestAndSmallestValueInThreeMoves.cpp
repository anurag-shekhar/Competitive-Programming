/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    int dfs(vector<int> &nums, int left, int right, int k)
    {
        if(k==0)
            return nums[right] - nums[left];
        
        int l = dfs(nums, left+1, right, k-1);
        int r = dfs(nums, left, right-1, k-1);
        return min(l,r);
    }
    int minDifference(vector<int>& nums) {
        
        int n = nums.size();
        if(n<5)
            return 0;
        sort(nums.begin(), nums.end());
        
        return dfs(nums, 0, n-1, 3);
    }
};

/*


*/
