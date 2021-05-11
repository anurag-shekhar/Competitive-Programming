/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NextPermutation.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        int n = nums.size();
        int i = n-2;
        
        while(i>=0 && nums[i] >= nums[i+1])
            i--;
       
        if(i<0)
        {
            sort(nums.begin(), nums.end());
            return ;
        }
        
        int j = i+1;
        while(j<n && nums[i] < nums[j])
            j++;
        j--;
     
        swap(nums[i], nums[j]);
        
        sort(nums.begin()+i+1, nums.end());
        return;
        
        
    }
};
