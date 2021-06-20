/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SingleNumberII.cpp
 * Created on : Sun Jun 20 2021
 ****************************************************************
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0 ;
        for(int i = 0; i<32; i++)
        {
            int countBit = 0;
            for(int j = 0; j<nums.size(); j++)
            {
                 if((nums[j]&(1<<i)) != 0 )
                     countBit++;
            }
            countBit %= 3;
            if(countBit)
                res |= (1<<i);
        }
        return res;
    }
};
