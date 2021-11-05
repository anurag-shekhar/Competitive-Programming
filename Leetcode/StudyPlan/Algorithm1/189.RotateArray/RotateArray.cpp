/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RotateArray.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    void reverse(vector<int>& nums, int left, int right)
    {
        while(left < right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            right--;
            left++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k%n;
        
        if(k==0)
            return;
        
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums,k, n-1);
        
    }
};
