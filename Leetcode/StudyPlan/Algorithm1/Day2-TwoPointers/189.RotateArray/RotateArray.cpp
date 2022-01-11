/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RotateArray.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    
    void rotate_helper(vector<int> &nums, int i, int j)
    {
        while(i<=j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }   
    }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        k = n-k;
        rotate_helper(nums, 0, k-1);
        rotate_helper(nums, k, n-1);
        rotate_helper(nums, 0, n-1);
    }
};