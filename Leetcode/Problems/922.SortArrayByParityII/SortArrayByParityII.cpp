/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SortArrayByParityII.cpp
 * Created on : Wed Sep 29 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();
        int evenPtr = n-1, oddPtr = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(nums[i]%2)
            {
                swap(nums[i], nums[oddPtr]);
                oddPtr++;
            }   
        }
        for(int i = n-1; i>=0; i--)
        {
            if(nums[i]%2==0)
            {
                swap(nums[i], nums[evenPtr]);
                evenPtr--;
            }   
        }
        
        
        
        int left = 0, right = n-1;
        
        while(left < right)
        {
            swap(nums[left], nums[right]);
            left+=2;
            right-=2;
        }
        return nums;
        
        
        
    }
};
