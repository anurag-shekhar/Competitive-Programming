/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseBits.cpp
 * Created on : Mon Jan 24 2022
 ****************************************************************
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t res = 0;
        
        int count = 32;
        while(count--)
        {
            res <<= 1;
            if(n&1)
                res +=1;
            n >>=1;
        }
        return res;
        
    }
};