/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SearchInRotatedSortedArray.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int Bsearch(vector<int> &nums, int l, int r, int target)
    {
        if(r < l)
            return -1;
        int m = (l+r)/2;
        
        if(nums[m] == target)
            return m;
        if(nums[l] <= nums[m])
        {
            if(nums[m] < target || target < nums[l]) //right
                return Bsearch(nums,m+1,r,target);
            else   //left 
                return Bsearch(nums,l,m-1,target);   
        }
        else 
        {
            if(target < nums[l] && nums[m] < target) //right
                return Bsearch(nums,m+1,r,target);
            else //left 
                return Bsearch(nums,l,m-1,target);
        }
    }
    int search(vector<int>& nums, int target) {
        
        return Bsearch(nums,0,nums.size()-1, target);
    }
};
