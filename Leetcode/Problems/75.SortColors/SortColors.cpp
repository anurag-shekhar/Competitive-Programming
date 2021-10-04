/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SortColors.cpp
 * Created on : Mon Oct 04 2021
 ****************************************************************
 */

class Solution {
public:
    int bringColorToFront(vector<int>& nums, int color, int currPtr)
    {
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(color == nums[i])
            {
                swap(nums[currPtr], nums[i]);
                currPtr++;
            }
        }
        return currPtr;
    }
    void sortColors(vector<int>& nums) {
    
        int currPtr = bringColorToFront(nums, 0,0);
        bringColorToFront(nums,1, currPtr);
    }
};
