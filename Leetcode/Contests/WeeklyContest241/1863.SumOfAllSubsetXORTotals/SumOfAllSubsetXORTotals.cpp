/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfAllSubsetXORTotals.cpp
 * Created on : Mon May 17 2021
 ****************************************************************
 */

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size();
        int res = 0;
        int bits = 0;
        for(int a : nums)
            bits |= a;
        
        res = bits* (1<<(n-1));
        return res;
    }
};
