/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindPeakElement.cpp
 * Created on : Wed Jul 14 2021
 ****************************************************************
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return 0;
        int left = 0, right = n-1;
        
        while(left <= right)
        {
            int mid = (right-left)/2 + left;
            
            if(mid == 0 && nums[mid] > nums[mid+1])
                return mid;
            if(mid == n-1 && nums[mid] > nums[mid-1])
                return mid;
            if(mid != 0 && mid != n-1 && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            
            if(mid ==0 || nums[mid] > nums[mid-1])
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return -1;
        
    }
};
