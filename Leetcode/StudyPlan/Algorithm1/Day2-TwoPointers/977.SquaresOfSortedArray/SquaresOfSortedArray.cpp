/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SquaresOfSortedArray.cpp
 * Created on : Wed Jan 12 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        int left = -1;
        int right = n;
        
        for(int i = 0; i<n; i++)
        {
            if(nums[i] >= 0)
            {
                left = i-1;
                right = i;
                break;
            }
            left = i;
        }
        
        vector<int> res;
        while(left >= 0 && right < n)
        {
            if(-1* nums[left] >= nums[right])
            {
                res.push_back(nums[right] * nums[right]);
                right++;
            }
            else
            {
                res.push_back(nums[left] * nums[left]);
                left--;
            }
        }
        
        while(left >= 0)
        {
            res.push_back(nums[left] * nums[left]);
            left--;
        }
        
        while(right < n)
        {
            res.push_back(nums[right] * nums[right]);
            right++;
        }
        return res;
    }
};