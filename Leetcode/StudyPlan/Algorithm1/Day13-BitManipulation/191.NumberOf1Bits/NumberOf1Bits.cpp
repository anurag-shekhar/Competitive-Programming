/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOf1Bits.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n)
        {
            if(n&1)
                count++;
            n >>=1;
        }
        return count;
    }
};