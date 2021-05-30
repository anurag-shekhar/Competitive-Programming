/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MissingNumber.cpp
 * Created on : Mon May 31 2021
 ****************************************************************
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xorAll = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            xorAll ^= nums[i];
            xorAll ^= i;
        }
        xorAll ^= n;
        return xorAll;
    }
};
