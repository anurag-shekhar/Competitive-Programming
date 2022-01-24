/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SingleNumber.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
     
        int res = 0;
        for(int a : nums)
            res ^= a;
        return res;
    }
};