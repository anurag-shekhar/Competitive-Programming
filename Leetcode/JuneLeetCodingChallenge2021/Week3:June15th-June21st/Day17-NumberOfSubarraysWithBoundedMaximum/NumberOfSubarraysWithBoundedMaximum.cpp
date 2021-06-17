/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfSubarraysWithBoundedMaximum.cpp
 * Created on : Thu Jun 17 2021
 ****************************************************************
 */

class Solution {
public:
    int getCount(int left, int right)
    {
        
        int n = right-left;
        return (n*(n+1))/2;
    }
    
    int getSubArray(vector<int>& nums, int target)
    {
        int l = 0;
        int r = 0;
        int res = 0;
        int n = nums.size();
        while(r<n)
        {
            if(nums[r] > target)
            {
                if(l!=r)
                    res += getCount(l,r);
                l = r+1;
            }    
            r++;
        }
        if(l!=r)
            res += getCount(l,r);
        return res;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        
        return getSubArray(nums, right) - getSubArray(nums, left-1);
        
    }
};

/* 

2 1 4 3
^.    ^
  

 1 2 3 2 1 
 
 1 2 3 2 1 
 1 2 3 2 
 1 2 3
 2 3 2 1 
 2 3 2
 2 3 
 3 2 1
 3 2
 3
 ^   ^       
*/
