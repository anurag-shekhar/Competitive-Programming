/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SplitArrayLargestSum.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool checkCapacity(vector<int>& nums, int m, int capacity)
    {
        int bucket = 0;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > capacity)
                return false;
            
            if(nums[i]+sum > capacity)
            {
                bucket++;
                if(bucket==m)
                    return false;
                sum = nums[i];
            }
            else 
                sum += nums[i];
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int n = nums.size();;
        int low = 0;
        int high = 0;
        
        for(int i = 0; i<n; i++)
        {
            high += nums[i];
            low = min(low, nums[i]);
        }
        
        int res = high;
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(checkCapacity(nums, m, mid))
            {
                res = mid;
                high = mid-1;
            }
            else 
                low = mid + 1;
        }
        return res;
    }
};
