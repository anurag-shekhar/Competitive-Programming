/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindMinimumInRotatedSortedArray.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:

    int findMin(vector<int>& nums) {
    
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left < right)
        {
            int mid = (right-left)/2 + left;

            if(mid-1 >= 0 && nums[mid-1] > nums[mid])
                return nums[mid];
            if(mid+1<n && nums[mid] > nums[mid+1])
                return nums[mid+1];
            
            if(nums[left] < nums[right])
            {
                if(nums[left] <= nums[mid])
                    right = mid-1;
                else
                    left = mid + 1;
            }
            else 
            {
                if(nums[left] <= nums[mid])
                    left = mid + 1;
                else 
                    right = mid -1;
            }   
        }
        return nums[left];
    }
};


/*
                      /  
                   /
                / 
             /
          /
        /
*/        
        
        
