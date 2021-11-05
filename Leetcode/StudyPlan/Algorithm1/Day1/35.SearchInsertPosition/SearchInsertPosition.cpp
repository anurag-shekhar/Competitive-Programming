/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SearchInsertPosition.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return low;
    }
};
