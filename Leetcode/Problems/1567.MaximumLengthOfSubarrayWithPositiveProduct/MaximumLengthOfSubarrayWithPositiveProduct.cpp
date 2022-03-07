/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumLengthOfSubarrayWithPositiveProduct.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        int posLen = 0;
        int negLen = 0;
        
        int n = nums.size();
        int res = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 0)
            {
                posLen = 0;
                negLen = 0;
            }
            else if(nums[i]  > 0)
            {
                posLen++;
                negLen = (negLen == 0) ? 0 : negLen+1;
            }
            else 
            {
                int temp = negLen;
                negLen = posLen+1;
                posLen = temp == 0 ? 0 : temp+1; 
            }
            res = max(posLen, res);
        }
        return res;
    }
};