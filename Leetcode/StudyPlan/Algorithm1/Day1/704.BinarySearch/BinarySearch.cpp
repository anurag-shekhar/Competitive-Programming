/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BinarySearch.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid+1;
            else 
                high = mid-1;
        }
        return -1;
        
    }
};
